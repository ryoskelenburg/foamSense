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
    avelageValue(inByteA1);
}

void SceneB::draw(){
    ofBackgroundHex(000000);
    std::cout << "fromAnalogA1: " << inByteA1 << endl;
}

void SceneB::newValue(int _newvalue) {
    inByteA1 = _newvalue;
}

void SceneB::avelageValue(int _value){
    inByteA1 = a * old + (1 - a) * inByteA1;
    old = inByteA1;
}
