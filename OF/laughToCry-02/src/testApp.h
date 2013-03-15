#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxNetwork.h"
#include "ofxOsc.h"
//#include "ofxSynth.h"
#include "ofxXmlSettings.h"
#include "ofx3DModelLoader.h"
#include "ofxAssimpModelLoader.h"
#include "ofxThreadedImageLoader.h"
#include "Particle.h"
#include "Trigger.h"
#include "Attractor.h"
#include "Grid.h"

#define borns 5

class testApp : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		
	
	vector<Particle*> particles;
	vector<Trigger*>* triggers;
    vector<Attractor*>* attractors;
	
	ofxOscSender oscSender;
	ofxOscMessage* msg;
    
    Grid grid;
    
    double zoom;
    
    
    double mx, my;
    double mxScreen, myScreen;
    
    vector<int> collisionHistory;
};
