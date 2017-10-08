//
//  SceneA.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#include <stdio.h>

#include "SceneA.h"

void SceneA::setup(){

}

void SceneA::update(){
    pressByte = ofMap(pressInput, 0, 1023, -200, 200);
}

void SceneA::draw(){
    
    ofTranslate(width/2, height/2);
    
    ofBackground(0);
    ofBeginShape();
    ofVertex(200,0+pressByte);
    ofVertex(-200,0+pressByte);
    ofVertex(-200,200);
    ofVertex(200,200);
    ofEndShape(true);
    
    
    ofSetColor(255);
    ofDrawBitmapString("value", 10, 10);
}


