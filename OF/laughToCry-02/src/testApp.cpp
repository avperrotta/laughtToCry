#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofBackground(30, 30, 30);
    ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
    
	oscSender.setup("localhost", 12345);
	
	triggers = new vector<Trigger*>;
    attractors = new vector<Attractor*>;
	
    
	/*
     for(int i=0; i<1; i++){
     attractors->push_back(new Attractor(triggers, "lsc-narrow-natural"));
     }
     */
	
	for(int i=0; i<8; i++){
		particles.push_back(new Particle(attractors, triggers, i + 1));
	}
	
	
	zoom = -5000.;
    
    grid.setup();
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
	ofxOscMessage msg;
    
    collisionHistory.clear();
	for(int i=0; i<particles.size(); i++){
		particles[i]->update();
        
        if(particles[i]->collision()){
            //cout<<endl<<"collision !";
            msg.clear();
            msg.setAddress("/particle-" + ofToString(particles[i]->index) + "/live");
            msg.addIntArg(particles[i]->preset->domainTime);
            msg.addFloatArg(particles[i]->preset->speedLimits.x);
            msg.addFloatArg(particles[i]->preset->speedLimits.y);
            msg.addFloatArg(particles[i]->preset->pitchLimits.x);
            msg.addFloatArg(particles[i]->preset->pitchLimits.y);
            msg.addIntArg(particles[i]->preset->bufferSize);
            oscSender.sendMessage(msg);
		}

	}
    
    for(int i=0; i<attractors->size(); i++){
        (*attractors)[i]->update();
        if((*attractors)[i]->status == 0){
            attractors->erase(attractors->begin() + i);
        }
    }
    
    
    
    if(ofGetFrameNum()%432 == 0){
        for(int i=0; i<3; i++){
            attractors->push_back(new Attractor(triggers, "lsc-narrow-natural"));
            attractors->push_back(new Attractor(triggers, "lsc-narrow-natural-slow"));
            attractors->push_back(new Attractor(triggers, "lsc-wide-veryHigh-verySlow"));
            attractors->push_back(new Attractor(triggers, "lsc-narrow-veryLow-verySlow"));
            attractors->push_back(new Attractor(triggers, "granular"));
        }
    }
     
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	glPushMatrix();
    glTranslated(0, 0, zoom);
    
    for(int i=0; i<attractors->size(); i++){
		(*attractors)[i]->draw();
	}
    
	for(int i=0; i<particles.size(); i++){
		particles[i]->draw();
	}
    
    grid.draw();
    
    glPopMatrix();
    
    
    ofSetColor(0, 0, 0, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(255, 255, 255);
    //ofDrawBitmapString(ofToString(mx) + " " + ofToString(my), mxScreen, myScreen);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key){
		case 'r':
			for(int i=0; i<triggers->size(); i++){
				(*triggers)[i]->setup();
			}
            for(int i=0; i<attractors->size(); i++){
				(*attractors)[i]->setup();
			}
            break;
        case OF_KEY_UP:
            zoom += 20.;
            cout<<endl<<"zoom = "<<zoom;
			break;
        case OF_KEY_DOWN:
            zoom -= 20.;
            cout<<endl<<"zoom = "<<zoom;
			break;
        case '1':
            for(int i=0; i<borns; i++){
                attractors->push_back(new Attractor(triggers, "lsc-narrow-natural"));
            }
            break;
        case '2':
            for(int i=0; i<borns; i++){
                attractors->push_back(new Attractor(triggers, "lsc-narrow-natural-slow"));
            }
            break;
        case '3':
            for(int i=0; i<borns; i++){
                attractors->push_back(new Attractor(triggers, "lsc-wide-veryHigh-verySlow"));
            }
            break;
        case '4':
            for(int i=0; i<borns; i++){
                attractors->push_back(new Attractor(triggers, "lsc-narrow-veryLow-verySlow"));
            }
            break;
        case '5':
            for(int i=0; i<borns; i++){
                attractors->push_back(new Attractor(triggers, "granular"));
            }
            break;
	}
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    mx = ofMap(x, 0, ofGetWidth(), -3850, 4850);
    my = ofMap(y, 0, ofGetHeight(), -2890, 3650);
    mxScreen = x;
    myScreen = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mx = ofMap(x, 0, ofGetWidth(), -3850, 4850);
    my = ofMap(y, 0, ofGetHeight(), -2890, 3650);
    mxScreen = x;
    myScreen = y;
    for(int i=0; i<10; i++){
        attractors->push_back(new Attractor(triggers, grid.getPreset(mx, my), ofRandom(mx - 700, mx + 700), ofRandom(my - 700, my + 700)));
    }
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
