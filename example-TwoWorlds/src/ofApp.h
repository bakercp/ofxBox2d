#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class ofApp: public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

    void mouseDragged(int x, int y, int button);

	void drawGravity(ofPoint p, ofPoint gravity);

	ofxBox2d box2dA;
	ofxBox2d box2dB;

	std::vector<std::shared_ptr<ofxBox2dCircle>> circlesA;
	std::vector<std::shared_ptr<ofxBox2dCircle>> circlesB;
	std::vector<std::shared_ptr<ofxBox2dRect>> sharedRects;

	ofRectangle boundsA;
	ofRectangle boundsB;
};
