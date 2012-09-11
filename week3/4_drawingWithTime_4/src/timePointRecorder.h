
#ifndef TIME_POINT_RECORDER_H
#define TIME_POINT_RECORDER_H

#include "ofMain.h"
#include "timePoint.h"

//--------------------------------------------------
class timePointRecorder {

	public: 
	
		void setup();
		void clear();
		void draw();
	
		void		startDrawing(float x, float y);
		void		addPoint (float x, float y);
		void		endDrawing();
		
		ofPoint		getPositionForTime( float time);
		ofPoint		getVelocityForTime( float time);
		
		bool		bHaveADrawing();
		float		getDuration();
	
	
		vector < timePoint >	pts;
		float					startTime;
		bool					bRecording;
	
	
};



#endif