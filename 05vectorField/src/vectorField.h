#ifndef VECTORFIELD_H
#define VECTORFIELD_H

#include "ofMain.h"

class vectorField {
	
    public:
	
		// the internal dimensions of the field:    (ie, 60x40, etc)
        int fieldWidth;
        int fieldHeight;
		int fieldSize;   // total number of "pixels", ie w * h
	
		// the external dimensions of the field:   (ie, 1024x768)
		int externalWidth;
		int externalHeight;
	
        vector <ofVec2f> field;

        vectorField();
        virtual ~vectorField();
		
		void setupField(int innerW, int innerH, int outerW, int outerH);   // pass in internal dimensions and outer dimensions
	
        void clear();
        void fadeField(float fadeAmount);
        void randomizeField(float scale);
        void draw();

		ofVec2f	getForceFromPos(float xpos, float ypos);

        void addOutwardCircle(float x, float y, float radius, float strength);
        void addInwardCircle(float x, float y, float radius, float strength);
        void addClockwiseCircle(float x, float y, float radius, float strength);
        void addCounterClockwiseCircle(float x, float y, float radius, float strength);
        void addVectorCircle(float x, float y, float vx, float vy, float radius, float strength);

    protected:
    private:
};

#endif // VECTORFIELD_H
