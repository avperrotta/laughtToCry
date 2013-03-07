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

Attractor::~Attractor(){
    
}

void Attractor::setup(){
    m0 = ofRandom(10., 50.);
    mass = m0;
    
    radius = 10*mass;
    
    x = ofRandom(-4000, 4000);
    y = ofRandom(-4000, 4000);
    
    age = 0;
    life = ofRandom(500, 3000);
    
    tg->x = x;
    tg->y = y - radius;
    tg->width = 10;
    tg->height = radius;
    
}

void Attractor::setup(double m){
    m0 = m;
    mass = m;
    
    radius = 10*m;
    
    x = ofRandom(-3000, 3000);
    y = ofRandom(-3000, 3000);
    
    age = 0;
    life = ofRandom(500, 3000);
}

void Attractor::update(){
    age++;
    if(age > life){
        setup();
    }
    
    ofMap(mass, 0, life, m0, 0.);
    
    
    
}

Trigger* Attractor::getTrigger(){
    return tg;
}

void Attractor::draw(){
    ofFill();
    ofSetColor(255, 153, 0, ofMap(age, 0, life, 255, 0));
    ofCircle(x, y, radius);
    ofFill();
    ofCircle(x, y, 2);
}