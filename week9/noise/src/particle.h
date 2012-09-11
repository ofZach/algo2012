#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofxVectorMath.h"



typedef struct{
	int			count;
	ofxVec2f	sum;
	float		distance;
	float		strength;
} flockingForce;



class particle{

	public:
        ofxVec2f pos;
        ofxVec2f vel;
        ofxVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particle();
		virtual ~particle(){};

        void resetForce();
		void addForce(float x, float y);
		void addRepulsionForce(float x, float y, float radius, float scale);
		void addAttractionForce(float x, float y, float radius, float scale);
		
		void addRepulsionForce(particle &p, float radius, float scale);
		void addAttractionForce(particle &p, float radius, float scale);
		void addClockwiseForce(particle &p, float radius, float scale);
		void addCounterClockwiseForce(particle &p, float radius, float scale);
	
		void addDampingForce();
 
		void addForFlocking(particle &p);
		void addFlockingForce();
	
		flockingForce cohesion;
		flockingForce seperation;
		flockingForce alignment;
	
	
		void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
		float damping;

    protected:
    private:
};

#endif // PARTICLE_H
