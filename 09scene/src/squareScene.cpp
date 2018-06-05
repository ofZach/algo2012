/*
 *  squareScene.cpp
 *  sceneExample
 *
 *  Created by zachary lieberman on 11/30/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "squareScene.h"



void squareScene::setup(){
		
}


void squareScene::update(){
	
}

void squareScene::draw(){
	
	ofSetColor(255,0,0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofRect(ofGetWidth()/2, ofGetHeight()/2, 300 + sin(ofGetElapsedTimef())*100, 300 + sin(ofGetElapsedTimef())*100);
	
}
	
