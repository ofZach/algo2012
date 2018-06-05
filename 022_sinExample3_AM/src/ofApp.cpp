#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	float modulator = ofMap( sin(ofGetElapsedTimef()*12.7), -1, 1, 0, 1);
	
	float xpos		= ofMap( sin(ofGetElapsedTimef()*3) * modulator, -1, 1, 0, ofGetWidth());
	
	
	ofSetColor(255,255,255);
	
	ofRect(xpos, 100, 20,20);
	
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

