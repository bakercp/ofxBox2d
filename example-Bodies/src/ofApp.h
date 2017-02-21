#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
    
	void draw() {
		ofPushMatrix();
		ofTranslate(getPosition());
		ofSetColor(color.r, color.g, color.b);
		ofFill();
		ofDrawCircle(0, 0, getRadius());
        ofPopMatrix();
	}

    ofColor color;

};

// -------------------------------------------------
class ofApp: public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

    float px = 0;
    float py = 0;
	bool bDrawLines = false;
	bool bMouseForce = false;
	
	ofxBox2d box2d; // the box2d world
	ofPolyline drawing; // we draw with this first
	ofxBox2dEdge edgeLine; // the box2d edge/line shape (min 2 points)
	std::vector<std::shared_ptr<ofxBox2dCircle>> circles; // default box2d circles
	std::vector<std::shared_ptr<ofxBox2dRect>> boxes; // default box2d rects
	std::vector<std::shared_ptr<CustomParticle>> customParticles; // this is a custom particle the extends a cirlce
};
