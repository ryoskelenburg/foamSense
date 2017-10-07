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
    ofSetHexColor(0xFFFFFF);
    font.drawString("Hi, I am SceneB!", 40, ofGetHeight() / 2.0);
}
