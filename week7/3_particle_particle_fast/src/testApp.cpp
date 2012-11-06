#include "testApp.h"
#include "particle.h"

#include "ofMain.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) { 
	return a->pos.x < b->pos.x; 
}			   
	  

//--------------------------------------------------------------
void testApp::setup(){

	for (int i = 0; i < 8000; i++){
		particle * p = new particle();
		myParticles.push_back(p);
		myParticles[i]->pos.set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
		myParticles[i]->vel.set(0,0);
	}
	
	ofSetCircleResolution(6);
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofBackground(0,0,0);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	// sort all the particles:

	sort( myParticles.begin(), myParticles.end(), comparisonFunction );		
	
	
	for (int i = 0; i < myParticles.size(); i++){
		myParticles[i]->resetForce();
	}
	
	for (int i = 0; i < myParticles.size(); i++){
		for (int j = i-1; j >= 0; j--){
			if ( fabs(myParticles[j]->pos.x - myParticles[i]->pos.x) >	10) break;	
			myParticles[i]->addRepulsionForce( *myParticles[j],10,1.1f);
		}
	}
	
	
	for (int i = 0; i < myParticles.size(); i++){
		myParticles[i]->addAttractionForce( 500,500,1500,0.01);
		myParticles[i]->addRepulsionForce( mouseX,mouseY,50,1.7);
		myParticles[i]->addDampingForce();
		myParticles[i]->update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255,255,255);
	// then draw:
	
	for (int i = 0; i < myParticles.size(); i++){
		 myParticles[i]->draw();
	}

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

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
}
