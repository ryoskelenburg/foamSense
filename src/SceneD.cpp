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
    
    tiltDefine[0] = 200;
    tiltDefine[1] = 200;
}

void SceneD::update(){
    
    avelageValue(inByteA3);
    avelageValue2(inByteA4);
    
    if(inByteA3 < tiltDefine[0] + 1){
        inByteA3 = tiltDefine[0];
    }
    
    if(inByteA4 < tiltDefine[1] + 1){
        inByteA4 = tiltDefine[1];
    }
    
    value = inByteA3;
    value2 = inByteA4;

    
    leftByte = ofMap(value,tiltDefine[0], maxTiltPram[0], 0, 100);
    rightByte = ofMap(value2,tiltDefine[1], maxTiltPram[1], 0, 100);

    leftSurface = ofMap(leftByte,0,100,0,390);
    rightSurface = ofMap(rightByte, 0, 100, 0, 390);
    
    if(value > maxTiltPram[0]){
        maxTiltPram[0] = value;

    }
    if(value2 > maxTiltPram[1]){
        maxTiltPram[1] = value2;
    }
//    if(value < tiltDefine[0]){
//        tiltDefine[0] = value;
//    }
//    if(value2 < tiltDefine[1]){
//        tiltDefine[1] = value2;
//    }
    //maxValue = 1023;
}

void SceneD::draw(){
    
//    std::cout << "ratioA3: " << leftByte << "%" << endl;
//    std::cout << "rawDetaA3: " << inByteA3 << endl;
//    std::cout << "maxPramA3: " << tiltDefine[0] << "/" << maxTiltPram[0] << endl;
//    std::cout << "ratioA4: " << rightByte << "%" << endl;
//    std::cout << "rawDetaA4: " << inByteA4 << endl;
//    std::cout << "maxPramA4: " << tiltDefine[1] << "/" << maxTiltPram[1] << endl;
        
    
    ofBackground(255);
    
    ofTranslate(width/2, height/2);
//    ofDrawBitmapString("TILT MODE", -300, -300);
//    ofDrawBitmapString("A3:" + ofToString(int(inByteA3)), -300, -280);
//    ofDrawBitmapString("A4:" + ofToString(int(inByteA4)), -300, -260);
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
    inByteA3 = a*old + (1-a)* inByteA3;
    old = inByteA3;
}

void SceneD::avelageValue2(int _value2){
    inByteA4 = a*old2 + (1-a)* inByteA4;
    old2 = inByteA4;
}
