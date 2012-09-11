#include "testApp.h"


bool pointInPolygon(float x, float y, vector<ofPoint>pts);
bool pointInPolygon(float x, float y, vector<ofPoint>pts){
	
	// code via Randolph Franklin...
	int i, j, c = 0;
	int nPts = pts.size();
	
	for (i = 0, j = nPts-1; i < nPts; j = i++) {
		if ((((pts[i].y <= y) && (y < pts[j].y)) ||
			 ((pts[j].y <= y) && (y < pts[i].y))) &&
			(x < (pts[j].x - pts[i].x) * (y - pts[i].y) / (pts[j].y - pts[i].y) + pts[i].x))
			c = !c;
	}
	return (bool) c;
}


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 500; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
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
	
	bLearnBakground = true;
	threshold = 30;
	bDrawDiagnostic = true;
	
	ofSetCircleResolution(10);
	setupBins(ofGetWidth(), ofGetHeight(), 19,14);
}

//--------------------------------------------------------------
void testApp::update(){

	//----------------------------------------------------- video stuff
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
				colorImg.mirror(false, true);
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
		contourFinder.findContours(grayDiff, 25,grayDiff.width * grayDiff.height, 1, false, false);
		
		contourParticles.clear();
		if (contourFinder.nBlobs > 0){
			
			for (int i = 0; i < contourFinder.blobs[0].nPts; i+=4){
				
				float scaleX = (float) ofGetWidth() / (float)grayDiff.width;
				float scaleY = (float) ofGetHeight() / (float)grayDiff.height;
				particle p;
				p.setInitialCondition( contourFinder.blobs[0].pts[i].x*scaleX, contourFinder.blobs[0].pts[i].y*scaleY, 0, 0);
				p.radius = 10;
				contourParticles.push_back(p);
			}
		}
	}
	
	
	//----------------------------------------------------- particle stuff
	
	
	// do binning for both
	for (int i = 0; i < particles.size(); i++){
		computeBinPosition( particles[i].pos.x, particles[i].pos.y,  &(particles[i].bitFlagW), &(particles[i].bitFlagH));
	}
	
	for (int i = 0; i < contourParticles.size(); i++){
		computeBinPosition( contourParticles[i].pos.x, contourParticles[i].pos.y,  &(contourParticles[i].bitFlagW), &(contourParticles[i].bitFlagH));
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	// particle v particle
	for (int i = 0; i < particles.size(); i++){
		unsigned int bitFlagH_pta = particles[i].bitFlagH;
		unsigned int bitFlagW_pta = particles[i].bitFlagW;
		for (int j = 0; j < i; j++){
			unsigned int bitFlagH_ptb = particles[j].bitFlagH;
			unsigned int bitFlagW_ptb = particles[j].bitFlagW;
			if ((bitFlagW_pta & bitFlagW_ptb) && (bitFlagH_pta & bitFlagH_ptb)){
				particles[i].addRepulsionForce( particles[j],20,0.7);
			}
        }
    }
	
	
	// do particle against hand: 
	for (int i = 0; i < particles.size(); i++){
		unsigned int bitFlagH_pta = particles[i].bitFlagH;
		unsigned int bitFlagW_pta = particles[i].bitFlagW;
		for (int j = 0; j < contourParticles.size(); j++){
			unsigned int bitFlagH_ptb = contourParticles[j].bitFlagH;
			unsigned int bitFlagW_ptb = contourParticles[j].bitFlagW;
			if ((bitFlagW_pta & bitFlagW_ptb) && (bitFlagH_pta & bitFlagH_ptb)){
				particles[i].addRepulsionForce(contourParticles[j].pos.x, contourParticles[j].pos.y, 30, 1.3f);
			}
		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addAttractionForce( 500,500,1500,0.01);
		particles[i].addForce(0,0.04f);
		particles[i].addDampingForce();
		particles[i].bounceOffWalls();
		particles[i].update();
		
	}
	
	
	// check if the particle is in the hand.
	// a few ways to do this, look for white pixel in the diff Image
	// or point in polygon.
	
	
	
	/*  // kind of heavy
	if (contourFinder.nBlobs > 0){
		for (int i = 0; i < particles.size(); i++){
			float posScaledX = particles[i].pos.x *  (float)(grayDiff.width) / (float)ofGetWidth();
			float posScaledY = particles[i].pos.y *  (float)(grayDiff.height) / (float)ofGetHeight();
			if (pointInPolygon(posScaledX, posScaledY, contourFinder.blobs[0].pts)){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()), 0, 0,0);
			}
		}
	}
	*/  
		
	
	// alternative, use the image pixels !! 
	// got to be very careful about the edges :)
	
	unsigned char * pixels = grayDiff.getPixels();
	for (int i = 0; i < particles.size(); i++){
		int posScaledX = (int)(particles[i].pos.x *  (float)(grayDiff.width) / (float)ofGetWidth());
		int posScaledY = (int)(particles[i].pos.y *  (float)(grayDiff.height) / (float)ofGetHeight());
		if (posScaledX < 0) posScaledX = 0;
		if (posScaledX > grayDiff.width-1) posScaledX = grayDiff.width-1;
		if (posScaledY < 0) posScaledY = 0;
		if (posScaledY > grayDiff.height-1) posScaledY = grayDiff.height-1;
		unsigned char myPixels = pixels[posScaledY * grayDiff.width + posScaledX];
		if (myPixels > 0){
			particles[i].setInitialCondition(ofRandom(0,ofGetWidth()), 0, 0,0);
		}
	}
	
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(0x000000);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	ofSetColor(0xff0000);
	for (int i = 0; i < contourParticles.size(); i++){
		contourParticles[i].draw();
	}
	
	
	if (contourFinder.nBlobs > 0){
		glPushMatrix();
		
		glScalef((float) ofGetWidth() / (float)grayDiff.width, (float) ofGetHeight() / (float)grayDiff.height, 1.0f);
		contourFinder.blobs[0].draw(0,0);
		glPopMatrix();
	}
	ofFill();
	
	if (bDrawDiagnostic == true){
		
		// draw the incoming, the grayscale, the bg and the thresholded difference
		ofSetColor(0xffffff);
		colorImg.draw(20,20);	
		grayImage.draw(360,20);
		grayBg.draw(20,280);
		grayDiff.draw(360,280);
		
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
