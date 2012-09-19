#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    ofSetCircleResolution(100);
    
    ofSetColor(0,0,0);
    
    angleA = 0;
    angleB = 0;
    
    circlePtA.set(200,200);
    circlePtB.set(600,200);
    
    
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){

    
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
void testApp::draw(){


    
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