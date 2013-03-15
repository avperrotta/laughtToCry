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
#include "Preset.h"

class Attractor : public Particle{
    
public:
    
    Attractor();
    ~Attractor();
    Attractor(vector<Trigger*>* tgV, std::string type);
    Attractor(vector<Trigger*>* tgV, Preset* ps);
    Attractor(vector<Trigger*>* tgV, Preset* ps, double x0, double y0);

    void setup();
    void setup(double m);
    void setup(double x0, double y0);
    void update();
    void draw();
    void clear();
    
    void setupTriggersVector(vector<Trigger*>* tgV);
    
    double m0;
    Trigger* tg;
    
    Trigger* getTrigger();
};

#endif
