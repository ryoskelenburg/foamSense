//
//  SceneA.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#include <stdio.h>
//#include "ofApp.h"
#include "SceneA.h"

void SceneA::setup(){
    
}

void SceneA::update(){
    pressByte = ofMap(pressInput, 0, 1023, -200, 200);
}

void SceneA::draw(){
    std::cout << "fromArduino: " << inByteA0 << endl;
    ofTranslate(width/2, height/2);
    
    ofBackground(0);
    ofBeginShape();
    ofVertex(200,0);
    ofVertex(-200,0);
    ofVertex(-200,200);
    ofVertex(200,200);
    ofEndShape(true);
    
    
    ofSetColor(255);
    ofDrawBitmapString("value", 10, 10);
}

void SceneA::newValue(int _newvalue) {
    //ofAppから来た値を変数に格納
    inByteA0 = _newvalue;
}
