#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	scenes[0] = new squareScene();
	scenes[1] = new circleScene();
	scenes[2] = new imageScene();
	
	currentScene = 0;
	
	for (int i = 0; i < 3; i++){
		scenes[i]->setup();
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	scenes[currentScene]->update();
}


//--------------------------------------------------------------
void testApp::draw(){
	
	scenes[currentScene]->draw();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	currentScene++;
	currentScene %= 3;
	
	((circleScene*)scenes[1])->sayHello();
	
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