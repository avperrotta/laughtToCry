//
//  Triggers.h
//  allAddonsExample
//
//  Created by André Perrotta on 2/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef TRIGGER_H
#define TRIGGER_H

#include "ofMain.h"
#include "Particle.h"

class Trigger : public Particle{
public:
	
	Trigger();
	~Trigger();
	
	void setup();
	void draw();
	
};


#endif