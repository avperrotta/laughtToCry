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

class Trigger;
class PresetZone;
class Attractor;
class Particle{
public:
	Particle();
	Particle(int ind);
	Particle(vector<PresetZone*>* pZ, vector<Trigger*>* tg, int ind);
    Particle(vector<Attractor*>* aT, vector<Trigger*>* tg, int ind);
	~Particle();
	
	int index;
	
	virtual void setup();
	virtual void update();
	virtual void draw();
	
	void setupPresets(double p0, double p1, double s0, double s1, int dt, int bf);
	
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
	
	int bufferSize;
	int domainTime;
	ofVec2f pitchLimits;
	ofVec3f speedLimits;
	string sample;
			 
	int status;
	
	int age;
    int life;
	
	vector<PresetZone*>* presetZones;
	vector<Trigger*>* triggers;
    vector<Attractor*>* attractors;
	
	void getClosestPresetZone();
	int closestPresetZone;
	void getPresets();
	
	bool collision();
	
	ofxOscMessage msg;
	void getMsg(ofxOscMessage* msg);
	
};




#endif