//
//  Particle.cpp
//  allAddonsExample
//
//  Created by André Perrotta on 2/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Particle.h"
#include "PresetZone.h"
#include "Trigger.h"
#include "Attractor.h"


Particle::Particle(){
	index = ofRandom(0, 9999);
	setup();
	
}

Particle::Particle(int ind){
	index = ind;
	setup();
}

Particle::Particle(vector<PresetZone*>* pZ, vector<Trigger*>* tg, int ind){
	index = ind;
	presetZones = pZ;
	triggers = tg;
	setup();
}

Particle::Particle(vector<Attractor*>* aT, vector<Trigger*>* tg, int ind){
	index = ind;
	attractors = aT;
	triggers = tg;
	setup();
}

Particle::~Particle(){
	
	
	
}

void Particle::setup(){
	
	radius = 10.;
	
	x = ofRandom(-500., 500.);
	y = ofRandom(-500., 500.);
	
	vx = ofRandom(2.8, 8.);
	vy = 0.0;
	
	setupPresets(0.8, 1., 0.00005, 0.3, ofRandom(10000, 32600), ofRandom(100, 3000));
	closestPresetZone = 0;
	
    maxV = 3.;
    maxV0 = 5.;
}

void Particle::setupPresets(double p0, double p1, double s0, double s1, int dt, int bf){
	pitchLimits = ofPoint(p0, p1);
	speedLimits = ofPoint(s0, s1);
	domainTime = dt;
	bufferSize = dt;
    
}

void Particle::update(){
    previousX = x;
    double a;
    ax = 0.;
    ay = 0.;
    
    double minDist = 999999999.;
    bool inside = false;
    
	for(int i=0; i<attractors->size(); i++){
        double dist = ofDist(x, y, (*attractors)[i]->x, (*attractors)[i]->y);
        if(dist < minDist){
            minDist = dist;
        }
        if(minDist < (*attractors)[i]->radius){
            inside = true;
        }
        a = -1.*3.*(*attractors)[i]->mass/dist;
        ax += a*(x - (*attractors)[i]->x)/dist;
        ay += a*(y - (*attractors)[i]->y)/dist;
    }
    
    if(inside){
        maxV += 0.5;
    }
    else {
        maxV = maxV0;
    }
    
    

    vx += ax;
    vy += ay;
    
    x += vx;
    y += vy;
    
    if(abs(vx) > maxV){
        double a = maxV/abs(vx);
        vx *= a;
    }
    if(abs(vy) > maxV){
        double a = maxV/abs(vy);
        vy *= a;
    }
	
}


void Particle::draw(){
	ofSetColor(255, 0, 0);
	//ofLine(x, y, (*presetZones)[closestPresetZone]->x, (*presetZones)[closestPresetZone]->y);
	ofFill();
	ofSetColor(220, 220, 220);
	ofCircle(x, y, radius);
	
	
}

void Particle::getPresets(){
	pitchLimits = (*presetZones)[closestPresetZone]->pitchLimits;
	speedLimits = (*presetZones)[closestPresetZone]->speedLimits;
	domainTime = (*presetZones)[closestPresetZone]->domainTime;
	bufferSize = (*presetZones)[closestPresetZone]->bufferSize;
}

void Particle::getClosestPresetZone(){
	double minDist = 10000000000000000000.0;
	for(int i=0; i<presetZones->size(); i++){
		if(ofDistSquared(x, y, (*presetZones)[i]->x, (*presetZones)[i]->y) < minDist){
			minDist = ofDistSquared(x, y, (*presetZones)[i]->x, (*presetZones)[i]->y);
			closestPresetZone = i;
			getPresets();
		}
	}
}

bool Particle::collision(){
	for(int i=0; i<triggers->size(); i++){
		if(y > (*triggers)[i]->y && y < ((*triggers)[i]->y + (*triggers)[i]->height)){
            if(previousX < (*triggers)[i]->x && x >= (*triggers)[i]->x){
                return true;
            }
            if(previousX > (*triggers)[i]->x && x <= (*triggers)[i]->x){
                return true;
            }
        }
	}
	return false;
}

void Particle::getMsg(ofxOscMessage* msg){
	msg->clear();
	msg->setAddress("/particle-" + ofToString(index) + "/live");
	msg->addIntArg(domainTime);
	msg->addFloatArg(speedLimits.x);
	msg->addFloatArg(speedLimits.y);
	msg->addFloatArg(pitchLimits.x);
	msg->addFloatArg(pitchLimits.y);
	msg->addIntArg(bufferSize);
}
