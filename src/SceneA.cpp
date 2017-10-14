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
}

void SceneA::update(){
    

    pressByte = ofMap(value,maxValue-400, maxValue, 0, 100);
    pressSponge = ofMap(pressByte,0,100,-200,250);
    
    
    avelageValue(inByteA0);
    if(inByteA0 < 401){
        inByteA0 =400;
    }
    
    value = inByteA0;

    if(value > maxValue){
        maxValue = value;
    }
    oldValue = value;
}

void SceneA::draw(){
    std::cout << "fromArduino: " << pressByte << "%" << endl;
    //std::cout << "MinArduino: " << inByteA0 << endl;
    std::cout << "MaxArduino: " << maxValue << endl;
    ofTranslate(width/2, height/2);
    
    ofBackground(0);
    ofBeginShape();
    ofVertex(200,-100+pressSponge);
    ofVertex(-200,-100+pressSponge);
    ofVertex(-200,200);
    ofVertex(200,200);
    ofEndShape(true);
    
    
    ofSetColor(255);
    ofDrawBitmapString("Please calibration!", -30, 10);
}

void SceneA::newValue(int _newvalue) {
    //ofAppから来た値を変数に格納
    inByteA0 = _newvalue;
}

void SceneA::avelageValue(int _Value){
    
    inByteA0 = a * old + (1 - a) * inByteA0;
    old = inByteA0;
}
