//
//  PresetZone.cpp
//  allAddonsExample
//
//  Created by André Perrotta on 2/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "PresetZone.h"

PresetZone::PresetZone(){
	setup();
}

PresetZone::PresetZone(int ind){
	index = ind;
	setup();
	//setupPresets(ofRandom(0.98, 1.), ofRandom(1.0, 1.1), ofRandom(0.00000001, 0.00005), ofRandom(0.005, 0.008), ofRandom(1000, 12000), ofRandom(1000, 10000));
    setupPresets(ofRandom(0.6, 1.), ofRandom(1.0, 1.3), ofRandom(0.00000001, 0.00005), ofRandom(0.5, 1.), ofRandom(300, 2500), ofRandom(1000, 10000));

}

PresetZone::~PresetZone(){
	
}

void PresetZone::setup(){
	width = ofRandom(100, 500);
	height = ofRandom(100, 500);
	
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	
	radius = ofRandom(0, 300);
	
	
}

void PresetZone::update(){
	
}

void PresetZone::draw(){
	ofNoFill();
	ofSetColor(0, 0, 255);
	ofCircle(x, y, radius);
	ofFill();
	ofCircle(x, y, 1);
	//ofDrawBitmapString(ofToString(index), x, y);
}