//
//  Attractor.h
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/6/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef allAddonsExample_Attractor_h
#define allAddonsExample_Attractor_h

#include "ofMain.h"
#include "Particle.h"
#include "Trigger.h"

class Attractor : public Particle{
    
public:
    
    Attractor();
    ~Attractor();
    
    void setup();
    void setup(double m);
    void update();
    void draw();
    
    double m0;
    Trigger* tg;
    
    Trigger* getTrigger();
};

#endif
