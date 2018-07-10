/*
 *  squareScene.cpp
 *  sceneExample
 *
 *  Created by zachary lieberman on 11/30/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "circleScene.h"


void circleScene::setup(){
	
}

void circleScene::update(){
	
}

void circleScene::draw(){
	
	ofSetColor(0,0,0);
	for (int i = 0; i < 100; i++){
		ofCircle(ofRandom(0,ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(50,100));
	}
}

