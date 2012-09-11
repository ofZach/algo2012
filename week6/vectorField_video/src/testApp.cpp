#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	
	
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.setVerbose(true);
		vidGrabber.initGrabber(320,240);
	#else
		vidPlayer.loadMovie("fingers.mov");
		vidPlayer.play();
	#endif
		
    colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);
	grayDiffSmall.allocate(60,40);
	
	bLearnBakground = true;
	threshold = 30;
	bDrawDiagnostic = true;
	bForceInward	= false; // do we push the particles away...
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	
	bool bNewFrame = false;
	
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.grabFrame();
		bNewFrame = vidGrabber.isFrameNew();
	#else
		vidPlayer.idleMovie();
		bNewFrame = vidPlayer.isFrameNew();
	#endif
	
	if (bNewFrame){
		
		#ifdef _USE_LIVE_VIDEO
				colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
		#else
				colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
		#endif
		
        grayImage = colorImg;
		if (bLearnBakground == true){
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}
		
		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);
		grayDiffSmall.scaleIntoMe(grayDiff);
		grayDiffSmall.blur(5); // really blur the image alot!
		VF.setFromPixels(grayDiffSmall.getPixels(), bForceInward, 0.05f);
	}
	
	
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();
	
	}
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	if (bDrawDiagnostic == true){
		
		// draw the incoming, the grayscale, the bg and the thresholded difference
		ofSetColor(0xffffff);
		colorImg.draw(20,20);	
		grayImage.draw(360,20);
		grayBg.draw(20,280);
		grayDiff.draw(360,280);
		// draw the blurry image
		grayDiffSmall.draw(360, 540, 320, 240);
		
    } else {
		
		ofEnableAlphaBlending();
		ofSetColor(255,255,255, 50);
		colorImg.draw(0,0,ofGetWidth(), ofGetHeight());	
		ofSetColor(0,130,130, 200);
		VF.draw();
		ofSetColor(0x000000);
		for (int i = 0; i < particles.size(); i++){
			particles[i].draw();
		}
	}
	
	ofSetColor(0,130,130, 200);
	ofRect(10,550,330,130);
	ofSetColor(0,0,0);
	ofDrawBitmapString("press ' ' (space) to snap background\npress 'd' to toggle diagnostic\ndrag mouse to add particles\npress 'r' to reset particles\npress 't' to toggle force direction", 20, 600);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' ' ){
		bLearnBakground = true;
	} else if (key == 'd'){	
		bDrawDiagnostic = !bDrawDiagnostic;
	} else if (key == 'r'){
		for (int i = 0; i < particles.size(); i++){
			particles[i].setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0,0);
		}
	} else if (key == 't'){
		bForceInward = !bForceInward;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles.erase(particles.begin());
	particle pt;
	pt.setInitialCondition(x, y, 0, 0);
	particles.push_back(pt);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
