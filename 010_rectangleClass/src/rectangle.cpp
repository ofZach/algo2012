#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
  
}

void rectangle::update(){

	pos.x = pos.x + ofRandom(-1,1);
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 20,20);
}
