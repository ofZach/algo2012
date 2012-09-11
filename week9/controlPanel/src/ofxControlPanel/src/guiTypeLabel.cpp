/*
 *  guiTypeLabel.cpp
 *  artvertiser
 *
 *  Created by damian on 10/10/10.
 *  Copyright 2010 frey damian@frey.co.nz. All rights reserved.
 *
 */


#include "guiTypeLabel.h"

//------------------------------------------------
void guiTypeLabel::setup(string text){
	setText( text );
}
void guiTypeLabel::setText( string text )
{
	name = text;
}

//-----------------------------------------------.
void guiTypeLabel::render(){
	ofPushStyle();
	glPushMatrix();
	guiBaseObject::renderText();
	glPopMatrix();
	ofPopStyle();
}
