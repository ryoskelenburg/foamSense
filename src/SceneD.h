//
//  SceneD.h
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/17.
//

#ifndef SceneD_h
#define SceneD_h

#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "BaseScene.h"

class SceneD : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    void newValue(int _newvalue, int _newvalue2);
    void avelageValue(int _value);
    void avelageValue2(int _value2);
    
    ofTrueTypeFont font;
    
    int inByteA3, inByteA4;
    int leftByte, rightByte;
    int leftSurface, rightSurface;
};

#endif /* SceneD_h */
