//
//  SceneB.h
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#ifndef SceneB_h
#define SceneB_h

#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "BaseScene.h"

// BaseSceneを継承したSceneB
class SceneB : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont font;
};


#endif /* SceneB_h */
