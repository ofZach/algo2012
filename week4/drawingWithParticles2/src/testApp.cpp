#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	bMousePressed = false;
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addDampingForce();
		particles[i].update();
	}
	

	// use xeno to catch the mouse:
	smoothedMouseX = 0.9f * smoothedMouseX + 0.1f * mouseX;
	smoothedMouseY = 0.9f * smoothedMouseY + 0.1f * mouseY;
	
	if (bMousePressed){
		float dx = smoothedMouseX - prevMouseX;
		float dy = smoothedMouseY - prevMouseY;
		particle myParticle;
		myParticle.setInitialCondition(mouseX,mouseY, dx,dy);
		particles.push_back(myParticle);
	}
	
	prevMouseX = smoothedMouseX;
	prevMouseY = smoothedMouseY;

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0x000000);
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < particles.size(); i++){
		ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
	}
	ofEndShape();
	
	
	
	ofSetColor(255,0,0);
	ofFill();
	//ofCircle(smoothedMouseX, smoothedMouseY,20);
	
	
	// filled line style
//	glLineWidth(8);
//	
//	ofBeginShape();
//	for (int i = 0; i < particles.size(); i++){
//		ofVertex(particles[i].pos.x, particles[i].pos.y);
//	}
//	ofEndShape();
//	
//	ofFill();
//	
//	for (int i = 0; i < particles.size(); i++){
//		ofCircle(particles[i].pos.x, particles[i].pos.y, 4.0);
//	}
	

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles.clear();
	bMousePressed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	bMousePressed = false;
}
