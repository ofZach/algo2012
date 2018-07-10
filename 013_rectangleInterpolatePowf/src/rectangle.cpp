#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	shaper = 2;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 20,20);
}


//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
	
	
	// powf (2, 3) = 8
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}