#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    ofBackground(0);
    
    //ディスプレイの設定
    //ofSetWindowPosition(1441,0);
    //ofSetFullscreen(true);
    //ofSetWindowShape(APP, <#int height#>)
    //ofSetWindowShape(1440, 900);
    
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
    
    //現在のシーンを0に
    currentScene = 0;
    scenes[currentScene]->setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    


    updateArduino();
    
    //３個の箱に値をanalog0~2の値を入れる
    for (int i=0; i<3; i++) {
        inByte[i] = ard.getAnalog(i);
        avelageAnalog(i);
    }
    
    //各SceneのnewValueに各配列に当たる変数を送る．
    scenes[currentScene]->newValue(inByte[currentScene]);
    scenes[currentScene]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    scenes[currentScene]->draw();
}

void ofApp::setupArduino(const int & version)
{
    ofRemoveListener(ard.EInitialized,this,&ofApp::setupArduino);
    for(int i = 0;i < 6;i++)
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
    inByte[_scene] = a * old + (1 - a) * ard.getAnalog(0);
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
