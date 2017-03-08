#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    ofSetFrameRate(100);
    
    sound.load("Justin Timberlake - Can't Stop the Feeling ( Lyrics Video ).mp3"); //音楽をロード
    sound.setLoop(true); //ループする
    sound.play(); //再生
    
    elapsedTime = 0;
    int bufferSize =256;
    
    left.assign(bufferSize, 0.0);
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    volume = ofSoundGetSpectrum(1);
    cout << volume[0] << endl;
    elapsedTime++;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(20, 240, 50);
    ofSetLineWidth(3);
    ofNoFill();
    slide++;
    if(slide==130)slide=0;
    ofBeginShape();
    for(unsigned int i = 0; i< left.size(); i++){
        ofVertex(i*10, 500 -left[i+slide]*4000.0f);
    }
    ofEndShape(false);

}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
    if(elapsedTime%8==0){
        for (int i = 0; i < bufferSize; i++){
            left[i]       = input[i*2]*0.5;
            
            
        }
        
        
    }
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
