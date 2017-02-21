#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"


// -------------------------------------------------

class ofApp: public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);

	ofxBox2d box2d;   // the box2d world
	std::vector<std::shared_ptr<ofxBox2dCircle>> circles; // default box2d circles
	std::vector<std::shared_ptr<ofxBox2dRect>> boxes; // defalut box2d rects
    
};

