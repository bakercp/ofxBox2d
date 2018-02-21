#include "ofApp.h"


void ofApp::setup()
{
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);

	box2d.init();
	box2d.enableEvents();   // <-- turn on the event listener
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
	
	// register the listener so that we get the events
	ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
    ofAddListener(box2d.contactPreSolveEvents, this, &ofApp::contactPreSolve);
    ofAddListener(box2d.contactPostSolveEvents, this, &ofApp::contactPostSolve);
    ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);

    ofDirectory directory("sfx/");
    directory.allowExt("mp3");

    for (auto file: directory)
    {
        auto sound = std::make_shared<ofSoundPlayer>();
        sound->load(file);
        sound->setMultiPlay(true);
        sound->setLoop(false);
        sounds.push_back(sound);
    }
}


void ofApp::contactStart(ofxBox2dContactArgs& e) {
	if(e.a != NULL && e.b != NULL) {
		
		// if we collide with the ground we do not
		// want to play a sound. this is how you do that
		if(e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
			
            SoundData* aData = reinterpret_cast<SoundData*>(e.a->GetBody()->GetUserData());
            SoundData* bData = reinterpret_cast<SoundData*>(e.b->GetBody()->GetUserData());

			if(aData) {
				aData->bHit = true;
				sounds[aData->soundID]->play();
			}
			
			if(bData) {
				bData->bHit = true;
				sounds[bData->soundID]->play();
			}
		}
	}
}


void ofApp::contactPreSolve(ofxBox2dPreSolveArgs& e)
{
    const b2Manifold* oldManifold = e.oldManifold;
    // You can use the oldManifold here.
    // ...
}


void ofApp::contactPostSolve(ofxBox2dPostSolveArgs& e)
{
    const b2ContactImpulse* _impulse = e.impulse;
    // You can use the impulse here.
    // ...
}


void ofApp::contactEnd(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		SoundData* aData = reinterpret_cast<SoundData*>(e.a->GetBody()->GetUserData());
		SoundData* bData = reinterpret_cast<SoundData*>(e.b->GetBody()->GetUserData());
		
		if(aData)
        {
			aData->bHit = false;
		}
		
		if(bData)
        {
			bData->bHit = false;
		}
	}
}


void ofApp::update() {
	
	box2d.update();
	
	// add some circles every so often
	if((int)ofRandom(0, 50) == 0) {
        auto c = std::make_shared<ofxBox2dCircle>();
		c->setPhysics(1, 0.5, 0.9);
		c->setup(box2d.getWorld(), (ofGetWidth()/2)+ofRandom(-30, 30), -20, ofRandom(20, 50));
		
		c->setData(new SoundData());
		SoundData * sd = (SoundData*)c->getData();
		sd->soundID = ofRandom(0, sounds.size());
		sd->bHit	= false;
		
		circles.push_back(c);	
	}
}

void ofApp::draw() {
	
	for(size_t i=0; i<circles.size(); i++) {
		ofFill();
		SoundData * data = (SoundData*)circles[i]->getData();
		
		if(data && data->bHit) ofSetHexColor(0xff0000);
		else ofSetHexColor(0x4ccae9);
		
		
		circles[i]->draw();
	}
	
	string info = "";
	info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);
}


void ofApp::keyPressed(int key) {
	if(key == 't') ofToggleFullscreen();
	if(key == '1') box2d.enableEvents();
	if(key == '2') box2d.disableEvents();
}


void ofApp::mousePressed(int x, int y, int button) {
    auto c = std::make_shared<ofxBox2dCircle>();
	c->setPhysics(1, 0.5, 0.9);
	c->setup(box2d.getWorld(), x, y, ofRandom(20, 50));
	
	c->setData(new SoundData());
	SoundData * sd = (SoundData*)c->getData();
	sd->soundID = ofRandom(0, sounds.size());
	sd->bHit = false;
	
	circles.push_back(c);
}
