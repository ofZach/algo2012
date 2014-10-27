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
	
	
	float sinOfTime				= sin( ofGetElapsedTimef() );
	float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
	
	
	ofBackground(sinOfTimeMapped, sinOfTimeMapped, sinOfTimeMapped);

	
	float sinOfTime2			= sin( ofGetElapsedTimef() + PI);
	float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 0, 255);
	
	ofSetColor(sinOfTimeMapped2, sinOfTimeMapped2, sinOfTimeMapped2);
	ofRect(100,100,ofGetWidth()-200, ofGetHeight()-200);
	
	

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

