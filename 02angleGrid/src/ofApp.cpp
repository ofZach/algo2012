#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    ofBackground(0,0,0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
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
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
