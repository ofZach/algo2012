#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255,255,255);
	//ofSetFrameRate(5);
	ofSetVerticalSync(true);
	
	colorScheme.loadImage("sunset.png");
}

//--------------------------------------------------------------
void ofApp::update(){

	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofEnableAlphaBlending();
	ofSetColor(255,255,255, 100);
	//colorScheme.draw(0,0, ofGetWidth(), ofGetHeight());
	
	ofSeedRandom(0); // always pick the same random numbers.
	
	for (int i = 0; i < mouseX*3; i++){
		float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
		float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
		
		ofColor col = getColorForPixel( ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
									   ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
			
		col.a = 85;	// set some alpha. 
		ofSetColor(col);
		ofCircle(x,y,ofRandom(4,40));
	}
	
	
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


ofColor ofApp::getColorForPixel(int x, int y){

	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= colorScheme.width) x = colorScheme.width-1;
	if (y >= colorScheme.height) y = colorScheme.height-1;
	
	return colorScheme.getColor(x,y);
}
