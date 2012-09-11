#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	
	ofBackground(0, 0, 0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	panel.setup("control", 770, 0, 300, 400);
	panel.addPanel("color", 1, false);
	
	panel.addPanel("geometry", 1, false);
	
	panel.setWhichPanel("color");
	panel.setWhichColumn(0);
	panel.addSlider("red", "VAL_RED", 0,0,255, false);
	panel.addSlider("green", "VAL_GREEN", 0,0,255, false);
	panel.addSlider("blue", "VAL_BLUE",0,0,255, false);
	
	panel.setWhichPanel("geometry");
	
	panel.addToggle("rect", "VAL_RECT", true);
	
	panel.loadSettings("settings.xml");
	
}

//--------------------------------------------------------------
void testApp::update(){

	panel.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	
	ofSetColor(panel.getValueF("VAL_RED"), panel.getValueF("VAL_GREEN"), panel.getValueF("VAL_BLUE"));
	
	if (panel.getValueB("VAL_RECT")){
		ofRect(10,10,800,600);
	} else {
		ofCircle(400,400,200);
	} 
	
	panel.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	panel.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	panel.mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	panel.mouseReleased();
}
