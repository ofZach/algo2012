/*
 *  traingleParticle.cpp
 *  algo_wk10_inheritance
 *
 *  Created by zachary lieberman on 11/8/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "triangleParticle.h"


void triangleParticle::draw(){

	float size = 4;
	ofPoint ptA = pos + ofPoint( cos(TWO_PI/3) * size, sin(TWO_PI/3) * size);
	ofPoint ptB = pos + ofPoint( cos(2*TWO_PI/3) * size, sin(2*TWO_PI/3) * size);
	ofPoint ptC = pos + ofPoint( cos(3*TWO_PI/3) * size, sin(3*TWO_PI/3) * size);
	
	ofTriangle(ptA, ptB, ptC);
}