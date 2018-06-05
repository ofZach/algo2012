#pragma once

/*
	ofxAutoControlPanel makes ofxControlPanel a little easier to work with.
	
	the control panel is autoamtically toggle-able using the tab key.
	the panel is hooked up to mouse, draw, and update events automatically.
	addPanel() does an addPanel() followed by a setWhichPanel() to avoid redundancy and mistakes.
	the fps is autoamtically drawn at the lower right corner of the screen.
*/

#include "ofxControlPanel.h"
#include "ofEvents.h"

class ofxAutoControlPanel : public ofxControlPanel {
public:
	ofxAutoControlPanel() {
		setXMLFilename("settings.xml");
		ofAddListener(ofEvents.update, this, &ofxAutoControlPanel::update);
		ofAddListener(ofEvents.draw, this, &ofxAutoControlPanel::draw);
		ofAddListener(ofEvents.keyPressed, this, &ofxAutoControlPanel::keyPressed);
		ofAddListener(ofEvents.mousePressed, this, &ofxAutoControlPanel::mousePressed);
		ofAddListener(ofEvents.mouseReleased, this, &ofxAutoControlPanel::mouseReleased);
		ofAddListener(ofEvents.mouseDragged, this, &ofxAutoControlPanel::mouseDragged);
	}
	void update(ofEventArgs& event) {
		ofxControlPanel::update();
	}
	void draw(ofEventArgs& event) {
		ofxControlPanel::draw();
		if(!hidden) {
			glColor4f(1, 1, 1, 1);
			ofFill();
			ofRect(ofGetWidth() - 45, ofGetHeight() - 25, 40, 20);
			glColor4f(0, 0, 0, 1);
			ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 40, ofGetHeight() - 10);
		}
	}
	void keyPressed(ofKeyEventArgs& event) {
		if(event.key == '\t') {
			if(hidden) {
				show();
			} else {
				hide();
			}
		}
	}
	void show() {
		ofxControlPanel::show();
		ofShowCursor();
	}
	void hide() {
		ofxControlPanel::hide();
		ofHideCursor();
	}
	void mousePressed(ofMouseEventArgs& event) {
		ofxControlPanel::mousePressed(event.x, event.y, event.button);
	}
	void mouseReleased(ofMouseEventArgs& event) {
		ofxControlPanel::mouseReleased();
	}
	void mouseDragged(ofMouseEventArgs& event) {
		ofxControlPanel::mouseDragged(event.x, event.y, event.button);
	}
	
	// by default, make sliders float
	void addSlider(string name, string xmlName, float value, float low, float high, bool isInt = false) {
		ofxControlPanel::addSlider(name, xmlName, value, low, high, isInt);
	}
	void addPanel(string panelName, int columns = 1) {
		ofxControlPanel::addPanel(panelName, columns);
		ofxControlPanel::setWhichPanel(panelName);
	}
};
