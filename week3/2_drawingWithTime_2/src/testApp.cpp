#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(255, 255, 255);
	bRecording = false;
	playbackStartTime = 0;
	
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	
	
	// -------------------------- draw the line
	ofSetColor(0,0,0);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < pts.size();i++){
		ofVertex(pts[i].x, pts[i].y);
	}
	ofEndShape();
	
	// -------------------------- draw the point at the current time
	ofPoint pos = getPositionForTime(ofGetElapsedTimef() - playbackStartTime);
	ofFill();
	ofSetColor(255,0,0);
	ofCircle(pos.x, pos.y, 10);
	
	
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

	
	bRecording = true;
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

	bRecording = false;
	playbackStartTime = ofGetElapsedTimef();
	 
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
ofPoint testApp::getPositionForTime(float time){
	
	// are we recording?
	
	if (bRecording == true){
		return ofPoint(0,0,0);
	} else if (pts.size() < 2){
		return ofPoint(0,0,0);
	}
	
	// now, let's figure out where we are in the drawing....
	
	// (a) figure out where we are in the cycle
	
	// (like % but for floats)
	while (time > pts[pts.size()-1].t){
		time -= pts[pts.size()-1].t;
	}
	
	
	ofPoint pos;
	
	for (int i = 0; i < pts.size()-1; i++){
		if (time >= pts[i].t && time < pts[i+1].t){
			
			// calculate pct: 
			
			float part = time - pts[i].t;
			float whole = pts[i+1].t - pts[i].t;
			float pct = part / whole;
			
			// figure out where we are between a and b
			
			
			pos.x = (1-pct) * pts[i].x + (pct) * pts[i+1].x;
			pos.y = (1-pct) * pts[i].y + (pct) * pts[i+1].y;
			
			
		}
	}
	
	return pos;

}


