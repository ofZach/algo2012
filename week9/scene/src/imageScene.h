/*
 *  squareScene.h
 *  sceneExample
 *
 *  Created by zachary lieberman on 11/30/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef _IMAGE_SCENE
#define _IMAGE_SCENE


#include "ofMain.h"
#include "baseScene.h"


class imageScene : public baseScene {
	
	
	void setup();
	void update();
	void draw();
	
	ofImage frog;
	
};




#endif


