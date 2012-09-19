#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(80,80,80);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(255,255,255);
    
    stroke.draw();
    
    
    
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    vector < ofPoint > pts = stroke.getVertices();
    
    for (int i = 0; i < pts.size(); i++){
        
        int i_m_1 = MAX(i-1,0);
        int i_p_1 = MIN(i+1, pts.size()-1);
        
        ofPoint pta = pts[i_m_1];
        ofPoint ptb = pts[i];
        ofPoint ptc = pts[i_p_1];
        
        ofPoint diff = ptc - pta;
        
        float angle = atan2(diff.y, diff.x);
        
        angle += PI/2;
        
        float width = 20; //diff.length();
        
        ofPoint offsetA;
        offsetA.x = ptb.x + width * cos(angle);
        offsetA.y = ptb.y + width * sin(angle);
        
        ofPoint offsetB;
        offsetB.x = ptb.x - width * cos(angle);
        offsetB.y = ptb.y - width * sin(angle);

        ofLine(offsetA, offsetB);
        
        //ofColor col;
        //col.setHsb(ofMap(angle, -PI/2, 3*PI/2, 0,255, true), 100,255, ofMap(angle, -PI/2, 3*PI/2, 0,255, true));
        //mesh.addColor(col);
        mesh.addVertex(offsetA);
        //mesh.addColor(col);

        mesh.addVertex(offsetB);
        
        
        
    }
    
    // draw the mesh
    ofEnableAlphaBlending();
    ofSetColor(255,120,0,100);
    ofFill();
    mesh.draw();
    
    
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

    
    // instead of adding every stroke, only add a stroke if it's a certain distance from the last point;
    
    ofPoint prevPt = stroke.getVertices()[stroke.getVertices().size()-1];
    
    float distance = (prevPt - ofPoint(x,y)).length();
    
    if (distance > 10){
        stroke.addVertex(x,y);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    stroke.clear();
    stroke.addVertex(x,y);
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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