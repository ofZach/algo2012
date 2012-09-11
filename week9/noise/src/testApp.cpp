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
	panel.addSlider("scale factor", "VAL_SCALE", 0.1,0.0001,0.3, false);
	panel.addSlider("z value", "VAL_Z", 0,0,10, false);
	panel.addToggle("use time", "VAL_USE_TIME", false);
	panel.loadSettings("settings.xml");
	
	
	pixels = new unsigned char[800*600];
	texture.allocate(800, 600, GL_LUMINANCE);
	
}

//--------------------------------------------------------------
void testApp::update(){

	panel.update();
	
	//float scalef = ofMap(mouseX, 0, ofGetWidth(), 0,1);
	
	float scale = panel.getValueF("VAL_SCALE");
	float zval = panel.getValueF("VAL_Z");
	bool bTime =  panel.getValueB("VAL_USE_TIME");
	
	for (int i = 0; i < 800; i++){
		for (int j = 0; j < 600; j++){
			
			
			if (bTime){
				pixels[j*800+i] = ofNoise(i*scale,j*scale,ofGetElapsedTimef())*255;
			} else {
				pixels[j*800+i] = ofNoise(i*scale,j*scale,zval)*255;
			}
		}
	}
	texture.loadData(pixels, 800, 600, GL_LUMINANCE);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	
	
	ofSetColor(255,255,255);
	texture.draw(0,0);
	
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
