//
//  SceneC.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#include <stdio.h>
#include "SceneC.h"

void SceneC::setup(){
    //font.loadFont("NotoSans-Bold.ttf", 50);
}

void SceneC::update(){
    
}

void SceneC::draw(){
    ofBackgroundHex(0xFFFFFF);
    ofSetHexColor(0xFFFFFF);
    font.drawString("Hi, I am SceneB!", 40, ofGetHeight() / 2.0);
}
