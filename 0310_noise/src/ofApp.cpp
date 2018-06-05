#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
}

//--------------------------------------------------------------
void ofApp::update(){

	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255,0,127);
	
	ofBeginShape();
	for (int i = 0; i < 100; i++){
		
		//float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());  // symetrical
		
		float add = ofNoise(i/20.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());

		ofVertex(	500 + (200 + 100 * add) * cos((i/100.0)*TWO_PI), 
					500 + (200 + 100 * add) * sin((i/100.0)*TWO_PI));
	}
	ofEndShape();
	
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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
