#include "ofApp.h"



class stroke{
    
public: 
    
    ofPolyline originalLine;
    ofPolyline animateTo;
    ofPolyline animated;
    
    ofPolyline animatedTarget;
    
    ofPoint newPta, newPtb;
    bool bDone;
    bool bFlip;
    
    
    
    void clear(){
        bDone = false;
        originalLine.clear();
        animateTo.clear();
        animated.clear();
        bFlip = false;
    }
    
    void done(){
        
       
        if (originalLine.getVertices().size() > 1){
            ofPoint ptA = originalLine.getVertices()[0];
            ofPoint ptB = originalLine.getVertices()[originalLine.getVertices().size()-1];
            
            
            
            ofPoint ptC;
            for (int i = 0; i < originalLine.getVertices().size(); i++){
                ptC += originalLine.getVertices()[i];
            }
            
            ptC /= (float)originalLine.getVertices().size();
            
            
            
            
            float len = originalLine.getPerimeter();
            
            
            
             newPta = ptC - (ptB - ptA).normalize() * (len/2);
             newPtb = ptC + (ptB - ptA).normalize() * (len/2);
            float distance = (newPta - newPtb).length();
            
            for (int i = 0; i < originalLine.getVertices().size(); i++){
                
                ofPoint pt = newPta + ((newPtb - newPta)/ originalLine.getVertices().size()) * i;
                animateTo.addVertex(pt.x, pt.y);
            }
            
            animated = originalLine;
            
            animatedTarget = animateTo;
            
             bDone = true;
            
            bFlip = false;
        }
        
    }
    
    void update(){
        
        if (bDone == true){
            for (int i = 0; i < animated.getVertices().size(); i++){
                animated.getVertices()[i] = 0.99f *  animated.getVertices()[i]  + 
                                            0.01f * animatedTarget.getVertices()[i];
                
            }
            
            float diff = 0;
            for (int i = 0; i < animated.getVertices().size(); i++){
                diff += (animated.getVertices()[i] - animatedTarget.getVertices()[i]).length();
            }
            //cout << diff << endl;
            if (diff < 2){
                if (bFlip == false){
                    animatedTarget = originalLine;
                } else {
                    animatedTarget = animateTo;
                }
                bFlip = !bFlip;
            }
        }
    }
    
    void draw(){
        if (bDone == true){
            animated.draw();
        } else {
            originalLine.draw();
            
        }
    }
    
};

stroke str;


vector < stroke > strs;

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(80,255,60);
    str.clear();
}

//--------------------------------------------------------------
void ofApp::update(){

    str.update();
    
    for (int i = 0; i < strs.size(); i++){
        strs[i].update();
    }
    
}


//--------------------------------------------------------------
void ofApp::draw(){

    
    
    str.draw();
    
    for (int i = 0; i < strs.size(); i++){
        strs[i].draw();
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

    str.originalLine.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    str.clear();
    str.originalLine.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    str.done();
    
    strs.push_back(str);
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
