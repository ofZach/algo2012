#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetVerticalSync(true);

	ofBackground(255, 255, 255);
	TPR.setup();
	playbackStartTime = 0;
	
	
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	
	// -------------------------- draw the line
	TPR.draw();
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		float angle = atan2(vel.y, vel.x);
		
		float lengthVel = ofDist(0,0,vel.x, vel.y);
		
		ofFill();
		ofSetColor(255,0,0);
		
		ofSetRectMode(OF_RECTMODE_CENTER);
		
		ofPushMatrix();
			ofTranslate(pos.x, pos.y, 0);
			ofRotateZ(angle * RAD_TO_DEG);
			//ofRect(0,0,50,50);
			ofRect(0,0,50 + lengthVel/2.0,50);			// this does some stretching based on velocity.
		ofPopMatrix();
		
	
		
		
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
	TPR.addPoint(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}



