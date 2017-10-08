//
//  SceneB.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#include <stdio.h>
#include "SceneB.h"

void SceneB::setup(){
    //font.loadFont("NotoSans-Bold.ttf", 50);
}

void SceneB::update(){
    
}

void SceneB::draw(){
    ofBackgroundHex(0xFFFF00);
    ofDrawRectangle(0, 0, 400, 400);
}
