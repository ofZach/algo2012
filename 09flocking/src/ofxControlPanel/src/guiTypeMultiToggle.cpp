#include "guiTypeMultiToggle.h"

//------------------------------------------------
void guiTypeMultiToggle::setup(string multiToggleName, int defaultBox, vector <string> boxNames){
	bNames = boxNames;
	value.addValue( (int)defaultBox, 0, bNames.size()-1);
	name = multiToggleName;

	float lineHeight = 0;
	for(unsigned int i = 0; i < bNames .size(); i++){
		float lineWidth = boxSpacing + boxSize + displayText.stringWidth(bNames[i]);

		if( lineWidth > hitArea.width ){
			hitArea.width       += lineWidth-hitArea.width;
			boundingBox.width   += lineWidth-hitArea.width;
		}

		lineHeight += displayText.stringHeight(bNames[i]);
	}

	if(lineHeight > hitArea.height){
		hitArea.height      += lineHeight-hitArea.height;
		boundingBox.height  += lineHeight-hitArea.height;
	}

}

//-----------------------------------------------
void guiTypeMultiToggle::updateValue(){
	//CB
	notify();	
}

//-----------------------------------------------.
void guiTypeMultiToggle::updateGui(float x, float y, bool firstHit, bool isRelative){
	if(!firstHit)return;

	if( state == SG_STATE_SELECTED){
		float relX = x - hitArea.x;
		float relY = y - hitArea.y;

		for(unsigned int i = 0; i < bNames.size(); i++){
			ofRectangle tmpRect(0, i * (boxSize+boxSpacing), boxSize, boxSize);
			if( isInsideRect(relX, relY, tmpRect) ){
				value.setValue(i, 0);
				break;
			}
		}

		//CB
		notify();
	}

}

//-----------------------------------------------
void guiTypeMultiToggle::notify(){
	guiCallbackData cbVal;
	cbVal.setup(xmlName, name);
	cbVal.addValueF(value.getValueI());
	ofNotifyEvent(guiEvent,cbVal,this);
	//CB
}

//-----------------------------------------------.
void guiTypeMultiToggle::render(){
	ofPushStyle();
	guiBaseObject::renderText();

		//draw the background
		ofFill();
		glColor4fv(bgColor.getColorF());
		ofRect(hitArea.x, hitArea.y, hitArea.width, hitArea.height);

		for(unsigned int i = 0; i < bNames.size(); i++){
			float bx = hitArea.x + 0;
			float by = hitArea.y + i * (boxSize+boxSpacing);

			if(value.getValueI() == i){
				ofFill();
			}else{
				ofNoFill();
			}

			glColor4fv(fgColor.getColorF());
			ofRect(bx, by, boxSize, boxSize);

			ofNoFill();
			glColor4fv(outlineColor.getColorF());
			ofRect(bx, by, boxSize, boxSize);

			glColor4fv(textColor.getColorF());
			displayText.renderString(bNames[i], bx + boxSize + boxSpacing, by + boxSize -2);
		}

	ofPopStyle();
}
