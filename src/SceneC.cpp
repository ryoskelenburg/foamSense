//
//  SceneC.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#include <stdio.h>
#include "SceneC.h"

void SceneC::setup(){
    ofSetFrameRate(60);
    
    spongeDefine = 140;
}

void SceneC::update(){
    avelageValue(inByteA2);
    if(inByteA2 < spongeDefine + 1){
        inByteA2 = spongeDefine;
    }
    
    value = inByteA2;
    
    pressByte = ofMap(value,spongeDefine, maxValue, 0, 100);
    pressSponge = ofMap(pressByte,0,100,0,200);
    
    if(value > maxValue){
        maxValue = value;
    }
}

void SceneC::draw(){
    
    std::cout << "%" << pressByte << "%" << endl;
    std::cout << "pressSponge" << pressSponge << "%" << endl;
    std::cout << "inByteA2: " << inByteA2 << endl;
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

void SceneC::newValue(int _newvalue) {
    //ofAppから来た値を変数に格納
    inByteA2 = _newvalue;
}

void SceneC::avelageValue(int _value){
    inByteA2 = a * old + (1 - a) * inByteA2;
    old = inByteA2;
}
