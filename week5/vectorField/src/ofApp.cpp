#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	VF.setupField(102, 76,ofGetWidth(), ofGetHeight());
	VF.randomizeField(6.5);	
}

//--------------------------------------------------------------
void ofApp::update(){
	VF.fadeField(0.99f);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	VF.draw();
	ofDisableAlphaBlending();
		
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
	if (button == 0){
		VF.addOutwardCircle(x,y, 100, 0.3) ;
	} else {
		VF.addCounterClockwiseCircle(x, y, 200, 0.3);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
}
