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
    currentLine.draw();
    
    ofSetColor(180,180,180);
    for (int i = 0; i < lines.size(); i++){
        lines[i].draw();
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

    currentLine.addVertex(x,y);
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    currentLine.addVertex(x,y);
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    // when we are done, push this back into the current line array: 
    lines.push_back(currentLine);
    currentLine.clear();

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