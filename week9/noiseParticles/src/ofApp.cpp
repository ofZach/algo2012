#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 200; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	bPressed = false;
	
	NF.setup();
	NF.scaleOfField = 0.01;
	
}

//--------------------------------------------------------------
void ofApp::update(){

	
	NF.setTime(ofGetElapsedTimef()*0.1);
	//NF.scaleOfField = ofMap(mouseX, 0,ofGetWidth(),0,0.01);
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		for (int j = 0; j < i; j++){
			if (!bPressed){
				particles[i].addRepulsionForce(particles[j], 30,1.5);
			} else {
				particles[i].addRepulsionForce(particles[j], 30,0.3);	
			}
		}
		
		if (bPressed){
			//particles[i].addAttractionForce(mouseX, mouseY, 2000,0.1);
			ofVec2f frcFromNoise = NF.getNoiseForPosition(particles[i].pos.x, particles[i].pos.y,0.32);
			particles[i].addForce(frcFromNoise.x, frcFromNoise.y);
		} else {
			particles[i].addAttractionForce(mouseX, mouseY, 2000,0.5);

		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	//NF.draw();
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	ofSetColor(0x000000);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	ofSetColor(0,0,0);
	ofRect(10,10,230,20);
	ofSetColor(255,255,255);
	ofDrawBitmapString("mouse press to use noise", 20, 23);
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
		
	
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
	bPressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
	
	bPressed = false;
}
