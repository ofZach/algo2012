#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    
    lastTime = ofGetElapsedTimef();
    duration = 5;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float diffTime = ofGetElapsedTimef() - lastTime;
    if (diffTime > duration){
        printf("hi ! at time %f \n", ofGetElapsedTimef());
        ofBackground(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
        lastTime = ofGetElapsedTimef();
        //duration = ofRandom(1,5);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

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
