//
//  SceneC.h
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#ifndef SceneC_h
#define SceneC_h

#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "BaseScene.h"

// BaseSceneを継承したSceneC
class SceneC : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    void newValue(int _newvalue, int _newvalue2);
    void avelageValue(int _value);
    
    ofTrueTypeFont font;
    
    int inByteA2;
};

#endif /* SceneC_h */
