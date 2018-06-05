#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    video.loadMovie("fingers.mov");
    video.setLoopState(OF_LOOP_NORMAL);
    //video.setSpeed(0.4);
    video.play();
}

//--------------------------------------------------------------
void ofApp::update(){

    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,180);
    video.draw(0,0);
    
    ofSetLineWidth(3);
    ofSetColor(255,0,0);
    TS.draw(video.getPosition());
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(video.getPosition());
    }
    
    ofDrawBitmapStringHighlight("press ' ' to clear", ofPoint(video.getWidth() + 50, 50), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press a to reset video position", ofPoint(video.getWidth() + 50, 80), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press + to increase video speed", ofPoint(video.getWidth() + 50, 110), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press - to increase video speed", ofPoint(video.getWidth() + 50, 140), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("video speed: " + ofToString(video.getSpeed(), 3), ofPoint(video.getWidth() + 50, 170), ofColor::magenta, ofColor::white);
                                
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        strokes.clear();
        TS.pts.clear();
    }
    
    if (key == 'a'){
        video.setPosition(0);
    }
    
    if (key == '+'){
        video.setSpeed(video.getSpeed()+0.05);
    }
    
    if (key == '-'){
        video.setSpeed(video.getSpeed()-0.05);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    TS.addPoint(video.getPosition(),ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    strokes.push_back(TS);
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
