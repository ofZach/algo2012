#include "ofApp.h"


class circleSpot {
    
    
public: 
    float innerRadius;
    float outerRadius;
    ofPoint pos;
    ofColor colorA;
    ofColor colorB;
    float pct;
    
    void setup(){
        pos.set(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()));
        innerRadius = ofRandom(20,100);
        outerRadius = innerRadius + ofRandom(20,300);
        colorA.setHsb(ofRandom(0,60),255,255);
        colorB.setHsb(ofRandom(0,255), 60,60);
        
        
    }
    
    void update(ofPoint mouse){
        float distance = (pos - mouse).length();
        pct = (distance - innerRadius) / (outerRadius - innerRadius);
        pct = ofClamp(pct, 0,1);
        
    }

    void draw(){
        ofColor mix;
        mix.r = (1-pct) * colorA.r + (pct) * colorB.r;
        mix.g = (1-pct) * colorA.g + (pct) * colorB.g;
        mix.b = (1-pct) * colorA.b + (pct) * colorB.b;
        ofSetColor(mix);
        ofCircle(pos, innerRadius * (pct));
    }
    
    
    
};


circleSpot s;
vector < circleSpot > spots;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(100);
    //s.setup();
    for (int i = 0; i < 1000; i++){
        circleSpot c;
        c.setup();
        spots.push_back(c);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < 1000; i++){
        spots[i].update(ofPoint(mouseX, mouseY));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 1000; i++){
        spots[i].draw();
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
