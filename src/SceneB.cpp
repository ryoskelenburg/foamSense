//
//  SceneB.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#include <stdio.h>
#include "SceneB.h"

void SceneB::setup(){
    ofSetFrameRate(60);
    spongeDefine = 100;
    
}

void SceneB::update(){
    
    
    
    avelageValue(inByteA1);//フィルターにかける
    if(inByteA1 < spongeDefine + 1){//閾値より下なら定数を代入する
//        for (int i = 150; i>0; i++) {
//            inByteA1 = i;
//            ofSleepMillis(1);
//        }
        inByteA1 = 0;
    }
    value = inByteA1;//valueに格納
    
    pressByte = ofMap(value,0, 500, 0, 150);
    //
    

    //pressSponge = ofMap(value,0,100,0,10);
    
    if(value > maxValue){
        maxValue = value;
    }
}

void SceneB::draw(){
    
    std::cout << "%%%%" << pressByte << "%" << endl;
    std::cout << "rawDeta: " << inByteA1 << endl;
    std::cout << "currentArduino: " << value << endl;
    std::cout << "MaxArduino: " << maxValue << endl;
    
    ofBackground(255);
    ofTranslate(width/2, height/2);
    ofRotateZ(pressByte);
    ofSetColor(0);
    ofDrawRectangle(0, 0, 400, 400);
    
}

void SceneB::newValue(int _newvalue, int _newvalue2) {
    inByteA1 = _newvalue;
}

void SceneB::avelageValue(int _value){
    inByteA1 = a * old + (1 - a) * inByteA1;
    old = inByteA1;
}
