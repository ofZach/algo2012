#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	ofSetVerticalSync(true);
	
	ofBackground(255, 255, 255);
	
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	//for (int i = 0; i < points.size(); i++){
//		points[i].x += ofRandom(-1,1);
//		points[i].y += ofRandom(-1,1);
//	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofNoFill();
	ofSetColor(0, 0, 0);
	
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
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

	ofPoint tempPt;
	tempPt.x = x;
	tempPt.y = y;
	points.push_back(tempPt);
	printf ("size of vector %i \n", points.size());
	
	
	if (points.size() > 50){
		points.erase(points.begin());
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	points.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

