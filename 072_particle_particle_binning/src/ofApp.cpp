#include "ofApp.h"
#include "particle.h"


//--------------------------------------------------------------
void ofApp::setup(){

    for (int i = 0; i < 2000; i++){
		particle p;
		p.pos.set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
		p.vel.set(0,0);
        myParticles.push_back(p);
	}
	
	setupBins(ofGetWidth(), ofGetHeight(), 15,15);
	
	ofBackground(0,0,0);
	ofSetCircleResolution(6);
	
	//ofSetVerticalSync(true); // turned off, to see frameRateChanges...
}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (int i = 0; i < myParticles.size(); i++){
		computeBinPosition( myParticles[i].pos.x, myParticles[i].pos.y,  &(myParticles[i].bitFlagW), &(myParticles[i].bitFlagH));
	}
	
	
	for (int i = 0; i < myParticles.size(); i++){
        myParticles[i].resetForce();
    }
	
	int count = 0;
	
    for (int i = 0; i < myParticles.size(); i++){
		
		unsigned int bitFlagH_pta = myParticles[i].bitFlagH;
		unsigned int bitFlagW_pta = myParticles[i].bitFlagW;
		
        for (int j = 0; j < i; j++){
			
			unsigned int bitFlagH_ptb = myParticles[j].bitFlagH;
			unsigned int bitFlagW_ptb = myParticles[j].bitFlagW;
			
			if ((bitFlagW_pta & bitFlagW_ptb) && (bitFlagH_pta & bitFlagH_ptb)){
				myParticles[i].addRepulsionForce( myParticles[j],15,1.8);
				count ++;
			}
        }
    }
	
	printf("%i \n", count);
	
    for (int i = 0; i < myParticles.size(); i++){
		myParticles[i].addAttractionForce( 500,500,1500,0.01);
		myParticles[i].addRepulsionForce( mouseX,mouseY,100,0.7);
		myParticles[i].addDampingForce();
		//myParticles[i].bounceOffWalls();
        myParticles[i].update();
    }
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	
	ofSetColor(0xff0000);
	
	ofEnableAlphaBlending();
	ofSetColor(255,255,255, 255);
	
	for (int i = 0; i < myParticles.size(); i++){
        // then draw:
		myParticles[i].draw();
    }
	
	
	
/*	ofSetColor(255,255,255, 255);

	 // draw based on mouse.
	unsigned int mouseBinX;
	unsigned int mouseBinY;
	computeBinPosition( mouseX, mouseY,  &mouseBinX, &mouseBinY);

	for (int i = 0; i < myParticles.size(); i++){
	    unsigned int bitFlagH_pta = myParticles[i].bitFlagH;
		unsigned int bitFlagW_pta = myParticles[i].bitFlagW;
		unsigned int bitFlagH_ptb = mouseBinY;
		unsigned int bitFlagW_ptb = mouseBinX;
		if ((bitFlagW_pta & bitFlagW_ptb) && (bitFlagH_pta & bitFlagH_ptb)){
			myParticles[i].draw();
		}
	}*/
	
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
	
}
