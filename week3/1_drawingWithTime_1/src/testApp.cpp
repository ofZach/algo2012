#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	
	ofDrawBitmapString("take a look at the console / in xcode, command-shift-r", ofPoint(30,30));
	
	ofSetColor(0,0,0);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < pts.size();i++){
		ofVertex(pts[i].x, pts[i].y);
	}
	ofEndShape();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

	timePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = ofGetElapsedTimef() - startTime;
	pts.push_back(temp);
	
	printf("adding point %i at time %f \n", pts.size(), ofGetElapsedTimef() - startTime);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	pts.clear();
	startTime = ofGetElapsedTimef();
	timePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = 0;
	pts.push_back(temp);
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

