//
//  SceneD.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/17.
//

#include <stdio.h>
#include "SceneD.h"

void SceneD::setup(){
    ofSetFrameRate(60);
    
    spongeDefine = 0;
}

void SceneD::update(){
    avelageValue(inByteA3);
    avelageValue2(inByteA4);
    
    if(inByteA3 < spongeDefine + 1){
        inByteA3 = spongeDefine;
    }
    
    value = inByteA3;
    value2 = inByteA4;
    
    leftByte = ofMap(value,spongeDefine, maxValue, 0, 100);
    rightByte = ofMap(value2,spongeDefine, maxValue, 0, 100);
    leftSurface = ofMap(leftByte,0,100,0,200);
    rightSurface = ofMap(rightByte, 0, 100, 0, 200);
    
//    if(value > maxValue){
//        maxValue = value;
//    }
    //maxValue = 1023;
}

void SceneD::draw(){
    
    std::cout << "ratioA3: " << pressByte << "%" << endl;
    std::cout << "currentRawDetaA3: " << inByteA3 << endl;
    std::cout << "maxPramA3: " << maxValue << endl;
    std::cout << "ratioA4: " << pressByte << "%" << endl;
    std::cout << "currentRawDetaA4: " << inByteA4 << endl;
    std::cout << "maxPramA4: " << maxValue << endl;
    
    ofBackground(255);
    
    ofTranslate(width/2, height/2);
    ofDrawBitmapString("TILT MODE", -300, -300);
    ofSetColor(0);
    ofBeginShape();
    ofVertex(200,200);//右下
    ofVertex(200,-200+rightSurface);//右上
    ofVertex(-200,-200+leftSurface);//左上
    ofVertex(-200,200);//左下
    ofEndShape(true);
    
}

void SceneD::newValue(int _newvalue, int _newvalue2) {
    //ofAppから来た値を変数に格納
    inByteA3 = _newvalue;
    inByteA4 = _newvalue2;
}

void SceneD::avelageValue(int _value){
    inByteA3 = a * old + (1 - a) * inByteA3;
    old = inByteA3;
}

void SceneD::avelageValue2(int _value2){
    inByteA4 = b * old2 + (1 - b) * inByteA4;
    old2 = inByteA4;
}
