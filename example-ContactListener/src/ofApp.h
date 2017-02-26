#pragma once


#include "ofMain.h"
#include "ofxBox2d.h"


class SoundData
{
public:
    ~SoundData()
    {
        std::cout << "destroyed!" << std::endl;
    }

    int soundID = -1;
    bool bHit = false;
};


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void mousePressed(int x, int y, int button);

    // this is the function for contacts
    void contactStart(ofxBox2dContactArgs &e);
    void contactPreSolve(ofxBox2dPreSolveArgs& e);
    void contactPostSolve(ofxBox2dPostSolveArgs& e);
    void contactEnd(ofxBox2dContactArgs &e);

    // when the ball hits we play these sound
    std::vector<std::shared_ptr<ofSoundPlayer>> sounds;

    ofxBox2d box2d; // the box2d world
    std::vector<std::shared_ptr<ofxBox2dCircle>> circles; // default box2d circles

};
