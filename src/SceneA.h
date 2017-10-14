//
//  SceneA.h
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#ifndef SceneA_h
#define SceneA_h

#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "BaseScene.h"

// BaseSceneを継承したSceneA
class SceneA : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    void newValue(int _newvalue);
    void avelageValue(int _value);

    
    int inByteA0;
    int value = 0;
    int oldDelta,oldValue,maxValue = 0;
};

#endif /* SceneA_h */
