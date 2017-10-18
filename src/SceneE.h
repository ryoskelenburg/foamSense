//
//  SceneE.h
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/18.
//

#ifndef SceneE_h
#define SceneE_h

#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "BaseScene.h"

class SceneE : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    void newValue(int _newvalue, int _newvalue2);
    void avelageValue(int _value);
    void avelageValue2(int _value2);
    
    int inByteA5;
    int value = 0;
};

#endif /* SceneE_h */
