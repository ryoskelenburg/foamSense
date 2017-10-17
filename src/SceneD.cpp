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
    
    spongeDefine = 140;
}

void SceneD::update(){
    avelageValue(inByteA3);
    if(inByteA3 < spongeDefine + 1){
        inByteA3 = spongeDefine;
    }
    
    value = inByteA3;
    
    pressByte = ofMap(value,spongeDefine, maxValue, 0, 100);
    pressSponge = ofMap(pressByte,0,100,0,200);
    
    if(value > maxValue){
        maxValue = value;
    }
}

void SceneD::draw(){
    
    std::cout << "%" << pressByte << "%" << endl;
    std::cout << "pressSponge" << pressSponge << "%" << endl;
    std::cout << "inByteA2: " << inByteA3 << endl;
    std::cout << "value: " << value << endl;
    std::cout << "MaxArduino: " << maxValue << endl;
    ofBackground(255);
    
    ofTranslate(width/2, height/2);
    ofSetColor(0);
    ofBeginShape();
    ofVertex(200,200);//右下
    ofVertex(200-pressSponge,-200);//右上
    ofVertex(-200-pressSponge,-200);//左上
    ofVertex(-200,200);//左下
    ofEndShape(true);
    
}

void SceneD::newValue(int _newvalue) {
    //ofAppから来た値を変数に格納
    inByteA3 = _newvalue;
}

void SceneD::avelageValue(int _value){
    inByteA3 = a * old + (1 - a) * inByteA3;
    old = inByteA3;
}
