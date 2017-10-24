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
    int newavelageValue(int _value);
    void avelageValue2(int _value2);
    void avelageValue(int _value);
    
    int inByteA5;
    float newvalue;
    int lowpassValue = 0;
    int arrayA5[10];
    int sumArray, aveArray;
    int value = 0;
};

#endif /* SceneE_h */
