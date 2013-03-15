//
//  Preset.cpp
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Preset.h"


Preset::Preset(){
    
}

Preset::~Preset(){
    
}

Preset::Preset(double p0, double p1, double s0, double s1, int dt){
    setupPreset(p0, p1, s0, s1, dt, dt);
    color = ofColor(255, 70, 138);
}

Preset::Preset(std::string type){
    //Preset for Live-Sample-Cloud with narrow pitch and speed limits around input values
    //Amplitude envelopes range spoken-word-size
    if(type == "lsc-narrow-natural"){
        setupPreset(0.85, 1.15, 0.7, 1.3, ofRandom(600, 12600), ofRandom(100, 3000));
        color = ofColor(72, 125, 255);
    }
    
    //Preset for Live-Sample-Cloud with narrow pitch limits around input values
    //Very slow speed - slow like sounds
    //Amplitude envelopes range spoken-word-size
    else if(type == "lsc-narrow-natural-slow"){
        setupPreset(0.95, 1.1, 0.01, 0.3, ofRandom(600, 12600), ofRandom(100, 3000));
        color = ofColor(255, 70, 138);
    }
    
    
    else if(type == "lsc-wide-veryHigh-verySlow"){
        setupPreset(10., 90.1, 0.0001, 0.003, ofRandom(1600, 22600), ofRandom(100, 3000));
        color = ofColor(70, 180, 138);
    }
    
    
    else if(type == "lsc-narrow-veryLow-verySlow"){
        setupPreset(0.6, 0.9, 0.001, 0.03, ofRandom(1600, 12600), ofRandom(100, 3000));
        color = ofColor(200, 110, 60);
    }
    
    
    else if(type == "granular"){
        setupPreset(0.5, 2.5, 0.00001, 3.3, ofRandom(600, 3000), ofRandom(100, 3000));
        color = ofColor(130, 60, 167);
    }
    
}

void Preset::setupPreset(double p0, double p1, double s0, double s1, int dt, int bf){
	pitchLimits = ofPoint(p0, p1);
	speedLimits = ofPoint(s0, s1);
	domainTime = dt;
	bufferSize = dt;
}