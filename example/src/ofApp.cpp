#include "ofApp.h"

#include "continuable.hpp"

inline cti::continuable<std::string> start_greetings(std::string) {
  return cti::make_ready_continuable<std::string>("world");
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();

    start_greetings("hello")
        .then([](std::string response) {
            ofLogNotice("ofApp") << "hello: " << response;
        })
        .then([]() {
            ofLogNotice("ofApp") << "waiting for 200ms";
            ofSleepMillis(200);
        })
        .then([]() {
            ofLogNotice("ofApp") << "done";
        });

    ofLogNotice("ofApp") << "normal log test";
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
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
