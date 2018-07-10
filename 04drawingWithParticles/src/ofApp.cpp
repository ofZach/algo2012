#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0,0,0);
	
	ofFill();
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	//ofFill()
	// picasso !!!
	
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < particles.size(); i++){
		ofVertex(particles[i].pos.x, particles[i].pos.y);
	}
	ofEndShape();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	float dx = x - prevMouseX;
	float dy = y - prevMouseY;

	particle myParticle;
	myParticle.setInitialCondition(x,y, dx*0.3,dy*0.3);
	particles.push_back(myParticle);
	
	
	//if (particles.size() > 50){
//		particles.erase(particles.begin());
//	}
	
	prevMouseX = x;
	prevMouseY = y;
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	particles.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
}
