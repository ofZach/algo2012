#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"

class ofApp : public ofSimpleApp{
	
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
	
		// get the previous mouse position
		float prevMouseX;
		float prevMouseY;
		
	
	
};

#endif
	
