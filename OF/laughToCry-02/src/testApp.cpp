#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofBackground(30, 30, 30);
    ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
    
	oscSender.setup("localhost", 12345);
	
	presets = new vector<PresetZone*>;
	triggers = new vector<Trigger*>;
    attractors = new vector<Attractor*>;
	
    
	
	for(int i=0; i<15; i++){
		attractors->push_back(new Attractor());
	}
    for(int i=0; i<attractors->size(); i++){
        triggers->push_back((*attractors)[i]->getTrigger());
    }
	
	for(int i=0; i<8; i++){
		particles.push_back(new Particle(attractors, triggers, i+1));
	}
	
	
	zoom = -5000.;

}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
	ofxOscMessage msg;
	for(int i=0; i<particles.size(); i++){
		particles[i]->update();
        if(particles[i]->collision()){
			//cout<<endl<<"collision !";
            msg.clear();
			msg.setAddress("/particle-" + ofToString(particles[i]->index) + "/live");
			msg.addIntArg(particles[i]->domainTime);
			msg.addFloatArg(particles[i]->speedLimits.x);
			msg.addFloatArg(particles[i]->speedLimits.y);
			msg.addFloatArg(particles[i]->pitchLimits.x);
			msg.addFloatArg(particles[i]->pitchLimits.y);
			msg.addIntArg(particles[i]->bufferSize);
			oscSender.sendMessage(msg);
		}
        
	}
    
    for(int i=0; i<attractors->size(); i++){
        (*attractors)[i]->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	glPushMatrix();
    glTranslated(0, 0, zoom);
    
    
    
    
	
    for(int i=0; i<attractors->size(); i++){
		(*attractors)[i]->draw();
	}
    
    for(int i=0; i<triggers->size(); i++){
		(*triggers)[i]->draw();
	}
    
    
	for(int i=0; i<particles.size(); i++){
		particles[i]->draw();
	}
    glPopMatrix();
    
    ofSetColor(0, 0, 0, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

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
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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
