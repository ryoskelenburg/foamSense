#pragma once

#include "ofMain.h"
#include "BaseScene.h"
#include "SceneA.h"
#include "SceneB.h"
#include "SceneC.h"

class ofApp : public ofBaseApp{
    
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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void avelageAnalog();
    void updateArduino();
    void setupArduino(const int & version);
    
    
    ofArduino ard;
    bool bSetupArduino;
    
    float a = 0.99;
    float old = 0;
    int output;
    int inByte;
    
    //    int inByte = 0;
    int xByte, yByte, zByte;
    
    
    int angle;
    
    vector <BaseScene *> scenes;
    
    int currentScene;
    
};
