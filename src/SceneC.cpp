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
    ofBackground(0);
    ofBeginShape();
    ofVertex(200,200);
    ofVertex(- 200,200);
    ofVertex(pressByte ,-200);
    ofVertex(400 + pressByte,-200);
    ofEndShape(true);
}
