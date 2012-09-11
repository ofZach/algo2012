#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	VF.setupField(102, 76,ofGetWidth(), ofGetHeight());
	VF.randomizeField(6.5);	
}

//--------------------------------------------------------------
void testApp::update(){
	VF.fadeField(0.99f);
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	VF.draw();
	ofDisableAlphaBlending();
		
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if (button == 0){
		VF.addOutwardCircle(x,y, 100, 0.3) ;
	} else {
		VF.addCounterClockwiseCircle(x, y, 200, 0.3);
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
