//
//  Preset.h
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef allAddonsExample_Preset_h
#define allAddonsExample_Preset_h

#include "ofMain.h"

class Preset{
public:
    
    
    Preset();
    ~Preset();
    
    Preset(std::string type);
    Preset(double p0, double p1, double s0, double s1, int dt);
    
    void setupPreset(double p0, double p1, double s0, double s1, int dt, int bf);
    
    int bufferSize;
	int domainTime;
	ofVec2f pitchLimits;
	ofVec3f speedLimits;
    std::string sample;
    
    ofColor color;
    
};

#endif
