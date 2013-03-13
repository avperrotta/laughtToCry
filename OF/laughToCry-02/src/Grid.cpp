//
//  Grid.cpp
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Grid.h"

Grid::Grid(){
    
}


Grid::~Grid(){
    
}


void Grid::setup(){
    
    
    //values for zoom = -5000;
    startX = -3850.;
    stepH = (4850. - (startX))/6.;
    
    startY = -2890.;
    stepV = (3650. - (startY))/3.;
    
}

void Grid::update(){
    
}

void Grid::draw(){
    ofSetColor(255, 255, 255, 150);
    
    for(int i=0; i<5; i++){
        ofLine(i*stepH + stepH + startX, -5000, i*stepH + stepH + startX, 5000);
    }
    
    for(int i=0; i<3; i++){
        ofLine(-5000, i*stepV + stepV + startY, 5000, i*stepV + stepV + startY);
    }
    
    
    
    ofDrawBitmapString("very-short", startX + 20, startY + 100);
    ofDrawBitmapString("short", startX + stepH + 20, startY + 100);
    ofDrawBitmapString("medium", startX + 2*stepH + 20, startY + 100);
    ofDrawBitmapString("long", startX + 3*stepH + 20, startY + 100);
    ofDrawBitmapString("very-long", startX + 4*stepH + 20, startY + 100);
    ofDrawBitmapString("freezing", startX + 5*stepH + 20, startY + 100);
    
    ofDrawBitmapString("h", startX + 20, startY + 500);
    ofDrawBitmapString("i", startX + 20, startY + 600);
    ofDrawBitmapString("g", startX + 20, startY + 700);
    ofDrawBitmapString("h", startX + 20, startY + 820);
    
    ofDrawBitmapString("n", startX + 20, startY + 500 + stepV);
    ofDrawBitmapString("a", startX + 20, startY + 600 + stepV);
    ofDrawBitmapString("t", startX + 20, startY + 700 + stepV);
    ofDrawBitmapString("u", startX + 20, startY + 800 + stepV);
    ofDrawBitmapString("r", startX + 20, startY + 900 + stepV);
    ofDrawBitmapString("a", startX + 20, startY + 1000 + stepV);
    ofDrawBitmapString("l", startX + 20, startY + 1100 + stepV);
    
    ofDrawBitmapString("l", startX + 20, startY + 500 + 2*stepV);
    ofDrawBitmapString("o", startX + 20, startY + 600 + 2*stepV);
    ofDrawBitmapString("w", startX + 20, startY + 700 + 2*stepV);
    

    
    
}