//
//  Attractor.cpp
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/6/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Attractor.h"

Attractor::Attractor(){
    
    tg = new Trigger();
    

    setup();
}

Attractor::Attractor(vector<Trigger*>* tgV, std::string type){
    triggers = tgV;
    tg = new Trigger();
    preset = new Preset(type);
    
    
    setup();
    
    
    
}

Attractor::~Attractor(){
    
}

void Attractor::setup(){
    
    
    m0 = ofRandom(10., 50.);
    mass = m0;
    
    radius = 10*mass;
    
    //x = ofRandom(-5700, 1700);
    //y = ofRandom(-1700, 1700);
    
    x = 4850;
    y = 3650;
    
    age = 0;
    life = ofRandom(150, 600);
    
    
    
    tg->setupPresets(preset);
    tg->x = x;
    tg->y = y - radius;
    tg->width = 10;
    tg->height = radius;
    
    triggers->push_back(tg);
    
    status = 1;
    
}

void Attractor::setup(double m){
    m0 = m;
    mass = m;
    
    radius = 10*m;
    
    x = ofRandom(-700, 700);
    y = ofRandom(-700, 700);
    
    age = 0;
    life = ofRandom(150, 600);
}

void Attractor::setupTriggersVector(vector<Trigger*>* tgV){
    triggers = tgV;
}

void Attractor::clear(){
    for(int i=0; i<triggers->size(); i++){
        if((*triggers)[i] == tg){
            triggers->erase(triggers->begin() + i);
        }
    }
    delete tg;
}

void Attractor::update(){
    age++;
    if(age > life){
        status = 0;
        clear();
        //setup();
    }
    
    ofMap(mass, 0, life, m0, 0.);
    
    
    
}

Trigger* Attractor::getTrigger(){
    return tg;
}

void Attractor::draw(){
    ofFill();
    ofSetColor(preset->color.r, preset->color.g, preset->color.b, ofMap(age, 0, life, 255, 0));
    ofCircle(x, y, radius);
    ofFill();
    ofCircle(x, y, 2);
    tg->draw();
}