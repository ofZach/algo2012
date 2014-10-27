#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	
	
	ofBackground(0, 0, 0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 60; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	
	panel.setup("control", 770, 0, 300, 400);
	panel.addPanel("flocking", 1, false);
	panel.setWhichPanel("flocking");
	panel.setWhichColumn(0);
	panel.addSlider("cohesion strength", "COHESION_STRENGTH", 0.01,0,1, false);
	panel.addSlider("cohesion radius", "COHESION_RADIUS", 50,0,200, false);
	panel.addSlider("alignment strength", "ALIGNMENT_STRENGTH", 0.01,0,1, false);
	panel.addSlider("alignment radius", "ALIGNMENT_RADIUS",  50,0,200, false);
	panel.addSlider("seperation strength", "SEPERATION_STRENGTH", 0.01,0, 1, false);
	panel.addSlider("seperation radius", "SEPERATION_RADIUS",  50,0,200, false);
	
	panel.addSlider("damping", "DAMPING", 0.01, 0.001, 0.5, false);
	
	panel.loadSettings("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

	panel.update();
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].cohesion.distance = panel.getValueF("COHESION_RADIUS");
		particles[i].alignment.distance = panel.getValueF("ALIGNMENT_RADIUS");
		particles[i].seperation.distance = panel.getValueF("SEPERATION_RADIUS");
		
		
		particles[i].cohesion.strength = panel.getValueF("COHESION_STRENGTH");
		particles[i].alignment.strength = panel.getValueF("ALIGNMENT_STRENGTH");
		particles[i].seperation.strength = panel.getValueF("SEPERATION_STRENGTH");
		
		particles[i].damping = panel.getValueF("DAMPING");
		
	}
	
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update

	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		for (int j = 0; j < particles.size(); j++){
			if (i != j){
				particles[i].addForFlocking(particles[j]);	
			}
		}
		
		
		
		// this was something we tried in class (partitcle move away from mouse...)
		particles[i].addRepulsionForce(mouseX, mouseY, 40, 0.4);
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addFlockingForce();
		particles[i].addDampingForce();
		particles[i].update();
	}
	
	
	// wrap torroidally.
	for (int i = 0; i < particles.size(); i++){
		ofVec2f pos = particles[i].pos;
		if (pos.x < 0) pos.x = ofGetWidth();
		if (pos.x > ofGetWidth()) pos.x = 0;
		if (pos.y < 0) pos.y = ofGetHeight();
		if (pos.y > ofGetHeight()) pos.y = 0;
		particles[i].pos = pos;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	ofSetColor(0xffffff);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	panel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	if (x < 500){
		particles.erase(particles.begin());
		particle myParticle;
		float randomAngle = ofRandom(0, TWO_PI);
		myParticle.setInitialCondition(x,y,cos(randomAngle),sin(randomAngle));
		particles.push_back(myParticle);
	}
	
	panel.mouseDragged(x,y,button);
	
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
	panel.mousePressed(x,y,button);
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
	
	panel.mouseReleased();
}
