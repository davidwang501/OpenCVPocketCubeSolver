#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include <math.h>
#include <sstream>

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void drawGrid();
    void drawColors();
    void updateFaces(std::string color);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    std::string getColor(int r, int g, int b);
    std::string getColor2(int r, int g, int b);
    std::string addSeparators();

    std::vector<vector<int>> faces;
    ofVideoGrabber cam;
    std::string scramble;
    std::string tempFace;
    std::string instructions;
    int face;
    ofTrueTypeFont font;
    
    
    ofImage uleft;
    ofImage uright;
    ofImage dleft;
    ofImage dright;
    
    
};