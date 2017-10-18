//
//  SceneE.cpp
//  foamSense
//
//  Created by Ryosuke Nakayama on 2017/10/18.
//

#include <stdio.h>
#include "SceneE.h"

void SceneE::setup(){
    ofSetFrameRate(60);
    
    
}

void SceneE::update(){
    value = ofMap(inByteA5, 0, 1023, 150, 2048);
    
}

void SceneE::draw(){
    
    ofBackground(255);
    
    ofTranslate(width/2, height/2);
    ofScale(1, 1);//x,y axis reverce.
    ofDrawBitmapString("BEND MODE", -300, -300);
    
    ofSetColor(0);
    ofBeginShape();
    ofEndShape(true);
    
    ofNoFill();
    ofFill();
    ofSetColor(0);
    //line(0,0, 200+100*cos(PI), 200+100*sin(PI));
    int curveRadius = value;// 曲率半径 ここが変数．
    
    //int curveRadius = radius/2;
    float arclength = 400;
    float theta = arclength/curveRadius;
    
    int GAP = 100;
    int CENTERX = 0;
    int CENTERY = 0+curveRadius;
    
    //ofDrawLine(CENTERX+(radius/2)*cos(PI*5/4), CENTERY + (radius/2)*sin(PI*5/4), CENTERX + 0.5*(radius+GAP)*cos(PI*5/4), CENTERY + 0.5*(radius+GAP)*sin(PI*5/4));
    //ofDrawLine(CENTERX+(radius/2)*cos(PI*7/4), CENTERY + (radius/2)*sin(PI*7/4), CENTERX + 0.5*(radius+GAP)*cos(PI*7/4), CENTERY + 0.5*(radius+GAP)*sin(PI*7/4));
    
    //
    ofPath curve, curveBottom;
    ofPoint p(0, curveRadius);
    //curve.arc(100, 100, 50, 50, 0, 360);
    curve.arc(p, curveRadius, curveRadius, -90 - (theta /2)*(180/PI) ,-90 + (theta /2)*(180/PI)  );
    curve.setCircleResolution(60);
    curve.setFillColor(0);
    curve.setFilled(true);
    curve.setStrokeColor(0);
    curve.setStrokeWidth(1);
    curve.draw();
    curveBottom.arc(p, curveRadius-50, curveRadius-50, -90 - (theta /2)*(180/PI) ,-90 + (theta /2)*(180/PI) );
    std::cout << "radius:" << inByteA5 << endl;
    curveBottom.setCircleResolution(600);
    curveBottom.setStrokeColor(0);
    curveBottom.setStrokeWidth(1);
    curveBottom.draw();
    
    ofSetColor(255);
    ofDrawCircle(p, curveRadius-50);
    //
    
    /*
     arc( CENTERX, CENTERY, radius, radius, PI*3/2-theta/2, PI*3/2+theta/2 );
     arc( CENTERX, CENTERY, radius+GAP, radius+GAP, PI*3/2-theta/2, PI*3/2+theta/2 );
     */
    
    //curveRadius = diameter/2;
    CENTERY=200+curveRadius;
    
    
    
}

void SceneE::newValue(int _newvalue, int _newvalue2) {
    inByteA5 = _newvalue;
}

void SceneE::avelageValue(int _value){
    
}

void SceneE::avelageValue2(int _value2){
    
}
