#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	
	myRectangle.pos.x = 120;
	myRectangle.pos.y = 40;
	
}

//--------------------------------------------------------------
void testApp::update(){

	myRectangle.update();
	
}



//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
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
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	// in class we looked at this -- click = new position
	//myRectangle.pos.x = ofRandom(0,ofGetWidth());
	//myRectangle.pos.y =  ofRandom(0,ofGetHeight());
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
