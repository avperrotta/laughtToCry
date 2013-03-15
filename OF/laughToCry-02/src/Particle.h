//
//  Particle.h
//  allAddonsExample
//
//  Created by André Perrotta on 2/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofxOsc.h"

class Preset;
class Trigger;
class Attractor;
class Particle{
public:
	Particle();
	Particle(int ind);
    Particle(vector<Attractor*>* aT, vector<Trigger*>* tg, int ind);
	~Particle();
	
	int index;
	
	virtual void setup();
	virtual void update();
	virtual void draw();
	
    Preset* preset;
	void setupPreset(Preset* ps);
	
	double x, y, z;
	double vx, vy, vz;
	double ax, ay, az;
	double fx, fy, fz;
    
    double previousX;
    
    double maxV;
    double maxV0;
    
    double width;
    double height;
	
	double radius;
    
    double mass;
	
	int status;
	
	int age;
    int life;
	
	vector<Trigger*>* triggers;
    vector<Attractor*>* attractors;
	
	
	Preset* getPreset();
	
	bool collision();
	
	
};




#endif