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
    ofSetFrameRate(60);
    
    spongeDefine = 400;
}

void SceneA::update(){
    
    
    avelageValue(inByteA0);
    if(inByteA0 < spongeDefine + 1){
        inByteA0 = spongeDefine;
    }
    
    value = inByteA0;
    
    pressByte = ofMap(value,maxValue - spongeDefine, maxValue, 0, 100);
    pressSponge = ofMap(pressByte,0,100,0,390);
    
    if(value > maxValue){
        maxValue = value;
    }
}

void SceneA::draw(){
    std::cout << "fromArduino: " << pressByte << "%" << endl;
    std::cout << "currentRawDeta: " << inByteA0 << endl;
    std::cout << "MaxArduino: " << maxValue << endl;
    ofTranslate(width/2, height/2);
    
    ofBackground(255);
    ofBeginShape();
    ofVertex(200,200);//右下
    ofVertex(200,-200+pressSponge);//右上
    ofVertex(-200,-200+pressSponge);//左上
    ofVertex(-200,200);//左下
    ofEndShape(true);
    
    //ofDrawRectangle(200, -100, 300, 500);
    
    
    ofSetColor(0);
    //ofDrawBitmapString("Please calibration!", -30, 10);
}

void SceneA::newValue(int _newvalue) {
    //ofAppから来た値を変数に格納
    inByteA0 = _newvalue;
}

void SceneA::avelageValue(int _Value){
    
    inByteA0 = a * old + (1 - a) * inByteA0;
    old = inByteA0;
}
