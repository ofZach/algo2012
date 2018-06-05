#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	scenes[0] = new squareScene();
	scenes[1] = new circleScene();
	scenes[2] = new imageScene();
	
	currentScene = 0;
	
	for (int i = 0; i < 3; i++){
		scenes[i]->setup();
	}
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	scenes[currentScene]->update();
}


//--------------------------------------------------------------
void ofApp::draw(){
	
	scenes[currentScene]->draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	currentScene++;
	currentScene %= 3;
	
	((circleScene*)scenes[1])->sayHello();
	
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
