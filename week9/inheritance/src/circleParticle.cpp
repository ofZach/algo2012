/*
 *  traingleParticle.cpp
 *  algo_wk10_inheritance
 *
 *  Created by zachary lieberman on 11/8/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "circleParticle.h"


void circleParticle::draw(){
	
	float size = 4;
	ofNoFill();
	ofCircle(pos.x, pos.y, size);
	ofFill();
}