/*
 *  noiseField.cpp
 *  class12
 *
 *  Created by zachary lieberman on 11/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "noiseField.h"


void noiseField::setup(){
	scaleOfField = 0.001f;
}


ofVec2f noiseField::getNoiseForPosition(float x, float y, float scale){

	float angle = ofNoise(x*scaleOfField,y*scaleOfField,noiseTime) * TWO_PI * 1.6;
		
	ofVec2f result;
	result.x = cos(angle);
	result.y = sin(angle);
	
	result *= scale;
	return result;

}

void noiseField::draw(){

	ofSetColor(127,127,255);
	for (int i = 0; i < ofGetWidth(); i+=10){
		for (int j = 0; j < ofGetHeight(); j+=10){
			
			ofVec2f noise = getNoiseForPosition(i,j,30);
			ofLine(i,j,i+noise.x, j+noise.y);
		}
	}
}

void	noiseField::setTime(float t){
	noiseTime = t;
}