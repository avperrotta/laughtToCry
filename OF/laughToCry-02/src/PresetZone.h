//
//  PresetZone.h
//  allAddonsExample
//
//  Created by André Perrotta on 2/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//
#ifndef PRESET_ZONE_H
#define PRESET_ZONE_H

#include "ofMain.h"
#include "Particle.h"

class PresetZone : public Particle{
public:
	PresetZone();
	PresetZone(int ind);
	~PresetZone();
	
	void setup();
	void update();
	void draw();
	
	double width;
	double height;
	
	ofRectangle bounds;
	
	
};




#endif