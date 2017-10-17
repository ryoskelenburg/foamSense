#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    ofBackground(0);
    
    //ディスプレイの設定
    ofSetWindowPosition(1441,0);
    ofSetFullscreen(true);
    //    ofSetWindowShape(APP_WIDTH, APP_HEIGHT);
    ofSetWindowShape(1440, 900);
    
    ard.connect("/dev/cu.usbmodem1411",57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = false;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
    //シーンの切り替え
    //シーンを新規の生成し、配列に追加
    // A
    BaseScene *sa = new SceneA();
    sa->setup();
    scenes.push_back(sa);
    // B
    BaseScene *sb = new SceneB();
    sb->setup();
    scenes.push_back(sb);
    // C
    BaseScene *sc = new SceneC();
    sc->setup();
    scenes.push_back(sc);
    // D
    BaseScene *sd = new SceneD();
    sd->setup();
    scenes.push_back(sd);
    
    //現在のシーンを0に
    currentScene = 0;
    scenes[currentScene]->setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    updateArduino();
    
    //"4"個の箱に値をanalog0~4の値を入れる
    for (int i=0; i<5; i++) {
        
        //int j = i - 3;
        if(i < 3){
            inByte[i] = ard.getAnalog(i);
        } else if(i == 3){
            tiltByte[0] = ard.getAnalog(i);
        } else if (i == 4){
            tiltByte[1] = ard.getAnalog(i);
        }
        
    }
    
    scenes[0]->newValue(inByte[0],0);
    scenes[1]->newValue(inByte[1],0);
    scenes[2]->newValue(inByte[2],0);
    scenes[3]->newValue(tiltByte[0],tiltByte[1]);
    //各SceneのnewValueに各配列に当たる変数を送る．
    //scenes[currentScene]->newValue(inByte[currentScene]);
    scenes[currentScene]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    scenes[currentScene]->draw();
}

void ofApp::setupArduino(const int & version)
{
    ofRemoveListener(ard.EInitialized,this,&ofApp::setupArduino);
    for(int i = 0;i < 5;i++)
    {
        ard.sendAnalogPinReporting(i, ARD_ANALOG);
    }
    bSetupArduino = true;
    
}

void ofApp::updateArduino(){
    // Arduinoをアップデート、全てのデータとメッセージを取得
    ard.update();
}

void ofApp::avelageAnalog(int _scene){
    inByte[_scene] = a * old + (1 - a) * ard.getAnalog(_scene);
    old = inByte[_scene];
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            //シーンの切り替え
            currentScene++;
            currentScene %= scenes.size();
            scenes[currentScene]->setup();
            break;
        case 'f':
            ofToggleFullscreen();
            break;
            
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
