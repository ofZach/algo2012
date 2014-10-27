#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	font.loadFont("cooperBlack.ttf", 30);

	
    ofBackground(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0x000000);
    
    ofEnableAlphaBlending();
	
    ofSetColor(255,255,255, 50);

    
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

    
    
        //starImage.draw(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (particles.size() > 100){
        particles.erase(particles.begin());
    }
    float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    particle temp;
    temp.setInitialCondition(mouseX,mouseY,vx, vy);	
    temp.font = &font;
    particles.push_back(temp);

    
    

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
}
