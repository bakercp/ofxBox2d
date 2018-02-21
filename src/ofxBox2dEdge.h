//
//  ofxBox2dEdge.h
//  example-Bodies
//
//  Created by Todd Vanderlin on 11/18/13.
//
//


#pragma once
#include "ofMain.h"
#include "ofxBox2dBaseShape.h"
#include "ofxBox2dPolygonUtils.h"

class ofxBox2dEdge : public ofxBox2dBaseShape, public ofPolyline {
    
private:
    bool bFlagShapeUpdate;
    
public:

    ofVboMesh mesh;

    OF_DEPRECATED_MSG("Use addVertices instead.", void addVertexes(ofPolyline &polyline) );
    OF_DEPRECATED_MSG("Use addVertices instead.", void addVertexes(std::vector<ofVec2f> &pts) );

    void addVertices(const ofPolyline& polyline);
    void addVertices(const std::vector<ofVec2f>& pts);

    void clear();
    void destroy();
    
    void create(b2World * b2dworld);
    void updateShape();
    void draw();
};
