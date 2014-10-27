#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    ofSetCircleResolution(100);
    
    ofSetColor(0,0,0);
    
    angleA = 0;
    angleB = 0;
    
    circlePtA.set(200,200);
    circlePtB.set(600,200);
    
    
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){

    
    float diffX = mouseX - circlePtA.x;
    float diffY = mouseY - circlePtA.y;
    float angleTo = atan2(diffY, diffX);
    angleA  = 0.97f * angleA + 0.03f * angleTo;
    
    
    
    diffX = mouseX - circlePtB.x;
    diffY = mouseY - circlePtB.y;
    angleTo = atan2(diffY, diffX);
    
    float diffAngle = (angleTo - angleB);
    if (diffAngle < -PI) diffAngle += TWO_PI;
    if (diffAngle > PI) diffAngle -= TWO_PI;
    
    angleB  += 0.03 * diffAngle;
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){


    
    ofNoFill();
    ofCircle(circlePtA.x,circlePtA.y,100);
    ofPoint ptA;
    ofPoint ptB;
    ptA.set(circlePtA.x + 90 * cos(angleA), circlePtA.y + 90 * sin(angleA));
    ptB.set(circlePtA.x + 110 * cos(angleA), circlePtA.y + 110 * sin(angleA));
    ofLine(ptA, ptB);
    
    
    ofNoFill();
    ofCircle(circlePtB.x,circlePtB.y,100);
    ptA.set(circlePtB.x + 90 * cos(angleB), circlePtB.y + 90 * sin(angleB));
    ptB.set(circlePtB.x + 110 * cos(angleB), circlePtB.y + 110 * sin(angleB));
    ofLine(ptA, ptB);
    
    
    
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
