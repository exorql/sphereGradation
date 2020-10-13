#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(100);
    ofBackground(0);
    auto sphere = ofIcoSpherePrimitive(200, 4);
    // メッシュの量
    sphere.setResolution(1);
    
    // メッシュの情報を抽出
    mesh = sphere.getMesh();
    for(int i=0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofColor(0,0,0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofColor color;
    for(int i=0; i < mesh.getVertices().size(); i++) {
        auto point = mesh.getVertices()[i];

        color.setHsb(ofMap(ofNoise(point.x * 0.005, point.y * 0.005, point.z * 0.005, ofGetFrameNum() * 0.008), 0, 1, 0, 220), 180, 230);
        mesh.setColor(i, color);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateY(ofGetFrameNum() * 0.15);
    ofColor centerColor = ofColor(130, 78, 68);
    ofColor edgeColor(0, 0, 0);
    // グラデーション設定
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    mesh.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
