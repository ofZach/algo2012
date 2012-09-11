#include "testApp.h"



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
void testApp::setup(){

    ofBackground(80,255,60);
    str.clear();
}

//--------------------------------------------------------------
void testApp::update(){

    str.update();
    
    for (int i = 0; i < strs.size(); i++){
        strs[i].update();
    }
    
}


//--------------------------------------------------------------
void testApp::draw(){

    
    
    str.draw();
    
    for (int i = 0; i < strs.size(); i++){
        strs[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    str.originalLine.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    str.clear();
    str.originalLine.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    str.done();
    
    strs.push_back(str);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}