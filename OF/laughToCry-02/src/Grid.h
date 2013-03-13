//
//  Grid.h
//  allAddonsExample
//
//  Created by Andre Perrotta on 3/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef allAddonsExample_Grid_h
#define allAddonsExample_Grid_h

#include "ofMain.h"

class Grid{
public:
    
    Grid();
    ~Grid();
    
    void setup();
    void update();
    void draw();
    
    float stepH;
    float stepV;
    float startX;
    float startY;
};

#endif
