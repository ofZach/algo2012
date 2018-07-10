#pragma once

#include "ofMain.h"


typedef struct {

    float timePct; // pct is based on movie position;
    ofPoint pos;
    
} timePoint;

class timeStroke {
public: 
    void addPoint(float pct, ofPoint pos){
        timePoint temp;
        temp.timePct = pct;
        temp.pos = pos;
        pts.push_back(temp);
    }
    
    void draw(float pct){
        
        if (pts.size() > 1){
            for (int i = 0; i < pts.size()-1; i++){
                if (pts[i].timePct < pct && pts[i+1].timePct < pct){
                    ofLine(pts[i].pos, pts[i+1].pos);
                }
            }
        }
    }
    
    vector < timePoint > pts;

};

class ofApp : public ofBaseApp{

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
		
    
        ofVideoPlayer video;
        
        timeStroke TS;
        vector < timeStroke > strokes;
    
        
};
