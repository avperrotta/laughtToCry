//
//  Grid.cpp
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Grid.h"

#define pitchWidth 40.



Grid::Grid(){
    
}


Grid::~Grid(){
    
}


void Grid::setup(){
    
    
    //values for zoom = -5000;
    startX = -3850.;
    endX = 4850;
    stepH = (endX - startX)/6.;
    
    
    startY = -2890.;
    endY = 3650;
    stepV = (endY - startY)/3.;
    
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

Preset* Grid::getPreset(int x, int y){
    
    //==============================================
    if(x >= startX && x <= startX + stepH){
        if(y >= startY && y <= startY + stepV){
            //cout<<endl<<"entrei 1!";
            return new Preset(2., 100., 0.6, 2.1, ofRandom(500, 1000));
        }
    }
    
    if(x >= startX && x <= startX + stepH){
        if(y > startY + stepV && y <= startY + 2*stepV){
            //cout<<endl<<"entrei 2!";
            return new Preset(0.9, 1.1, 0.6, 2.1, ofRandom(500, 1000));
        }
    }
    
    if(x >= startX && x <= startX + stepH){
        if(y > startY + 2*stepV && y <= startY + 3*stepV){
            //cout<<endl<<"entrei 3!";
            return new Preset(0.3, 0.9, 0.6, 2.1, ofRandom(500, 1000));
        }
    }
    //==============================================
    
    //==============================================
    if(x > startX + stepH && x <= startX + 2*stepH){
        if(y >= startY && y <= startY + stepV){
            //cout<<endl<<"entrei 4!";
            return new Preset(2., 100., 0.5, 1.5, ofRandom(800, 2500));
        }
    }
    
    if(x > startX + stepH && x <= startX + 2*stepH){
        if(y > startY + stepV && y <= startY + 2*stepV){
            //cout<<endl<<"entrei 5!";
            return new Preset(0.9, 1.1, 0.5, 1.5, ofRandom(800, 2500));
        }
    }
    
    if(x > startX + stepH && x <= startX + 2*stepH){
        if(y > startY + 2*stepV && y <= startY + 3*stepV){
            //cout<<endl<<"entrei 6!";
            return new Preset(0.3, 0.9, 0.5, 1.5, ofRandom(800, 2500));
        }
    }
    //==============================================
    
    //==============================================
    if(x > startX + 2*stepH && x <= startX + 3*stepH){
        if(y >= startY && y <= startY + stepV){
            //cout<<endl<<"entrei 7!";
            return new Preset(2., 100., 0.1, 1.5, ofRandom(1600, 3500));
        }
    }
    
    if(x > startX + 2*stepH && x <= startX + 3*stepH){
        if(y > startY + stepV && y <= startY + 2*stepV){
            //cout<<endl<<"entrei 8!";
            return new Preset(0.9, 1.1, 0.1, 1.5, ofRandom(1600, 3500));
        }
    }
    
    if(x > startX + 2*stepH && x <= startX + 3*stepH){
        if(y > startY + 2*stepV && y <= startY + 3*stepV){
            //cout<<endl<<"entrei 9!";
            return new Preset(0.3, 0.9, 0.1, 1.5, ofRandom(1600, 3500));
        }
    }
    //==============================================
    
    //==============================================
    if(x > startX + 3*stepH && x <= startX + 4*stepH){
        if(y >= startY && y <= startY + stepV){
            //cout<<endl<<"entrei 10!";
            return new Preset(2., 100., 0.005, 0.1, ofRandom(3000, 6500));
        }
    }
    
    if(x > startX + 3*stepH && x <= startX + 4*stepH){
        if(y > startY + stepV && y <= startY + 2*stepV){
            //cout<<endl<<"entrei 11!";
            return new Preset(0.9, 1.1, 0.005, 0.1, ofRandom(3000, 6500));
        }
    }
    
    if(x > startX + 3*stepH && x <= startX + 4*stepH){
        if(y > startY + 2*stepV && y <= startY + 3*stepV){
            //cout<<endl<<"entrei 12!";
            return new Preset(0.3, 0.9, 0.005, 0.1, ofRandom(3000, 6500));
        }
    }
    //==============================================
    
    //==============================================
    if(x > startX + 4*stepH && x <= startX + 5*stepH){
        if(y >= startY && y <= startY + stepV){
            //cout<<endl<<"entrei 13!";
            return new Preset(2., 100., 0.00005, 0.001, ofRandom(5000, 11500));
        }
    }
    
    if(x > startX + 4*stepH && x <= startX + 5*stepH){
        if(y > startY + stepV && y <= startY + 2*stepV){
            //cout<<endl<<"entrei 14!";
            return new Preset(0.9, 1.1, 0.00005, 0.001, ofRandom(5000, 11500));
        }
    }
    
    if(x > startX + 4*stepH && x <= startX + 5*stepH){
        if(y > startY + 2*stepV && y <= startY + 3*stepV){
            //cout<<endl<<"entrei 15!";
            return new Preset(0.3, 0.9, 0.00005, 0.001, ofRandom(5000, 11500));
        }
    }
    //==============================================
    
    //==============================================
    if(x > startX + 5*stepH && x <= startX + 6*stepH){
        if(y >= startY && y <= startY + stepV){
            //cout<<endl<<"entrei 16!";
            return new Preset(2., 100., 0.000001, 0.00005, ofRandom(8000, 16500));
        }
    }
    
    if(x > startX + 5*stepH && x <= startX + 6*stepH){
        if(y > startY + stepV && y <= startY + 2*stepV){
            //cout<<endl<<"entrei 17!";
            return new Preset(0.9, 1.1, 0.000001, 0.00005, ofRandom(8000, 16500));
        }
    }
    
    if(x > startX + 5*stepH && x <= startX + 6*stepH){
        if(y > startY + 2*stepV && y <= startY + 3*stepV){
            //cout<<endl<<"entrei 18!";
            return new Preset(0.3, 0.9, 0.000001, 0.00005, ofRandom(8000, 16500));
        }
    }
    //==============================================
    
    
}









