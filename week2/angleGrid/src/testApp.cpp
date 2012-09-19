#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    ofBackground(0,0,0);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
    
    ofSetColor(255,255,255);
    
    for (int i = 0; i < ofGetWidth(); i+=20){
        for (int j = 0; j < ofGetHeight(); j+=20){
        
            ofPoint pt(i,j);
            ofPoint diff = ofPoint(mouseX, mouseY) - pt;
            
            float angle = atan2(diff.y, diff.x);
            float dist = diff.length();
            
            if (dist < 200){
            ofLine(pt.x, pt.y, pt.x - 10 * sin(angle), pt.y + 10 * cos(angle));
            }
            
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}