/*
 *  timePointRecorder.cpp
 *  drawingWithTime
 *
 *  Created by zachary lieberman on 9/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "timePointRecorder.h"

//-------------------------------------------------
void timePointRecorder::setup(){
	bRecording = false;
}

//-------------------------------------------------
void timePointRecorder::clear(){
	pts.clear();
}

//-------------------------------------------------
void timePointRecorder::draw(){
	ofSetColor(0,0,0);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < pts.size();i++){
		ofVertex(pts[i].x, pts[i].y);
	}
	ofEndShape();	
}

//-------------------------------------------------
void timePointRecorder::startDrawing(float x, float y){
	clear();
	bRecording = true;
	startTime = ofGetElapsedTimef();
	timePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = 0;
	pts.push_back(temp);
}

//-------------------------------------------------
void timePointRecorder::addPoint (float x, float y){
	timePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = ofGetElapsedTimef() - startTime;
	pts.push_back(temp);
}

//-------------------------------------------------
void timePointRecorder::endDrawing(){
	bRecording = false;
}

//-------------------------------------------------
bool timePointRecorder::bHaveADrawing(){
	if (bRecording == true){
		return false;
	} else if (pts.size() < 2){
		return false;
	}
	
	return true;
}


float timePointRecorder::getDuration(){
	float duration = 0;
	if (bHaveADrawing() == true){
		duration =  pts[pts.size()-1].t;
	}
	return duration;
}



//-------------------------------------------------
ofPoint	 timePointRecorder::getPositionForTime( float time){
	
	// are we recording?
	if (bHaveADrawing() == false){
		return ofPoint(0,0,0);
	}
		
	// now, let's figure out where we are in the drawing...
	ofPoint pos;
	for (int i = 0; i < pts.size()-1; i++){
		if (time >= pts[i].t && time <= pts[i+1].t){
			
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


//-------------------------------------------------
ofPoint	 timePointRecorder::getVelocityForTime( float time){
	
	// to get the velcoity, look back a bit of time, and at the current time
	// and get the difference 
	// veclocity = pos at time 1 - pos at time 0... 
	
	ofPoint prevPt = getPositionForTime( MAX(time - 0.09f, 0));		// check for where we were 0.05 seconds ago
	ofPoint currPt = getPositionForTime(time);							// check for where we are now.
	
	ofPoint diff;
	diff.x = currPt.x - prevPt.x;
	diff.y = currPt.y - prevPt.y;
	
	return diff;
}