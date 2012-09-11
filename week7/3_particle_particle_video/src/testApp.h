#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"

#include "ofxOpenCv.h"
#include "binner.h"

//#define _USE_LIVE_VIDEO		// uncomment this to use a live camera
// otherwise, we'll use a movie file


class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		// let's make a vector of them
		vector <particle> particles;
	
		bool bDrawDiagnostic;
	
		#ifdef _USE_LIVE_VIDEO
			ofVideoGrabber 		vidGrabber;
		#else
			ofVideoPlayer 		vidPlayer;
		#endif
		
		ofxCvColorImage			colorImg;
		
		ofxCvGrayscaleImage 	grayImage;
		ofxCvGrayscaleImage 	grayBg;
		ofxCvGrayscaleImage 	grayDiff;
		ofxCvContourFinder		contourFinder;
		
		int 				threshold;
		bool				bLearnBakground;

		vector <particle>	contourParticles;
	
};

#endif
	
