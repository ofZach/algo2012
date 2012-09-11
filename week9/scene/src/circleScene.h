/*
 *  squareScene.h
 *  sceneExample
 *
 *  Created by zachary lieberman on 11/30/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef _CIRCLE_SCENE
#define _CIRCLE_SCENE


#include "ofMain.h"
#include "baseScene.h"


class circleScene : public baseScene {
	
public: 
	
	void setup();
	void update();
	void draw();
	
	void sayHello(){
		printf("hi!\n");
	}
};




#endif


