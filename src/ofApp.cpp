#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    ofBackground(0);
    
    ofSetWindowPosition(1441,0);
    //ofSetFullscreen(true);
    //ofSetWindowShape(APP, <#int height#>)
    //ofSetWindowShape(1440, 900);
    
    //mySerial.setup("/dev/cu.usbmodem1411",57600);
    ard.connect("/dev/cu.usbmodem1411",57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    
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
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ard.update();
    avelageAnalog();
    //inByte = mySerial.readByte();//0~255
    //inByte = ard.getAnalog(0);
    xByte = ofMap(output, 300, 1023, -200, 200);
    yByte = ofMap(output, 700, 930, -400, 400);
    
    zByte = ofMap(output, 250, 1023, 0, 45);
    
    scenes[currentScene]->update();
}


void ofApp::setupArduino(const int & version)
{
    ofRemoveListener(ard.EInitialized,this,&ofApp::setupArduino);
    for(int i = 0;i < 6;i++)
    {
        ard.sendAnalogPinReporting(i, ARD_ANALOG);
    }
}

void ofApp::avelageAnalog(){
    
    output = a * old + (1 - a) * ard.getAnalog(0);
    old = output;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
        std::cout << "width: " << output << endl;
    //    std::cout << "height: " << height << endl;
    
    ofSetColor(255);
    ofTranslate(width/2, height/2);
    //ofRotateZ(zByte);
    
    //ofSetColor(ofColor::white);
    //ofDrawBitmapString("value: " + ofToString(xByte), -300, -300);
    
    //--------- rotate --------
    
    //ofDrawRectangle(0, 0, 400, 400);
    
    
    //--------- compress -----
    
//        ofBeginShape();
//        ofVertex(200,0+xByte);
//        ofVertex(-200,0+xByte);
//        ofVertex(-200,200);
//        ofVertex(200,200);
//        ofEndShape(true);
    
    //--------- bend ---------
    
            ofBeginShape();
            ofVertex(yByte,-200);
            ofVertex(yByte - 400,-200);
            ofVertex(yByte - 400,200);
            ofVertex(yByte,200);
            ofEndShape(true);
    
    //--------- shear ---------
    
//    ofBeginShape();
//    ofVertex(200,200);
//    ofVertex(- 200,200);
//    ofVertex(xByte ,-200);
//    ofVertex(400 + xByte,-200);
//    ofEndShape(true);
    
    // 現在表示しているシーンを描画
    scenes[currentScene]->draw();
    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            currentScene = 0;
            break;
        case '2':
            currentScene = 1;
            break;
        case '3':
            currentScene = 2;
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
