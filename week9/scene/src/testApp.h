#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "circleScene.h"
#include "squareScene.h"
#include "imageScene.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		baseScene  * scenes[3];
		int currentScene;
	
		
};
