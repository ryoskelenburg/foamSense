//
//  BaseScene.h
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/07.
//

#ifndef BaseScene_h
#define BaseScene_h

#pragma once
#include "ofMain.h"
#include "ofApp.h"

// 全てのシーンの雛形
class BaseScene {
    
public:
    //仮想関数 (virtual) として定義する
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void newValue(int _newvalue, int _newvalue2){};
    virtual void calibrationMode(int _minvalue,int _maxvalue){};
    virtual void keyPressed (int key){};
    virtual void keyReleased(int key){};
    virtual void mouseMoved(int x, int y ){};
    virtual void mouseDragged(int x, int y, int button){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(int x, int y, int button){};
    virtual void windowResized(int w, int h){};
    virtual void avelageValue(int value){};
    virtual void avelageValue2(int value2){};
    
    
    int width = ofGetWidth();
    int height = ofGetHeight();

    int pressInput;
    int pressByte,pressSponge;
    
    int spongeDefine = 0;
    int tiltDefine[2];
    int maxTiltPram[2];
    int value = 0,value2 =0;
    int oldDelta = 0,oldValue = 0;
    int maxValue;
    
    float a = 0.99;
    float b = 0.99;
    float old;
    float old2;
    int output;
};

#endif /* BaseScene_h */
