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
    void newValue(int _newvalue);
    void avelageValue(int _value);
    
    ofTrueTypeFont font;
    
    int inByteA3, inByteA4;
};

#endif /* SceneD_h */
