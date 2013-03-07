//
//  Triggers.cpp
//  allAddonsExample
//
//  Created by André Perrotta on 2/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Trigger.h"

Trigger::Trigger(){
	setup();
}

Trigger::~Trigger(){
	
}

void Trigger::setup(){
	
}

void Trigger::draw(){
    ofFill();
	ofSetColor(0, 255, 0);
	ofRect(x, y, width, height);
}