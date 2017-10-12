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
    
    int inByte1;
    
    ofTrueTypeFont font;
    
    
};

#endif /* SceneA_h */
