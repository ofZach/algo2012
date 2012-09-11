/*
 *  traingleParticle.cpp
 *  algo_wk10_inheritance
 *
 *  Created by zachary lieberman on 11/8/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "squareParticle.h"


void squareParticle::draw(){
	float size = 4;
	ofRect(pos.x - size/2, pos.y - size/2, size, size);
}