/*
 *  guiTypeLabel.h
 *  artvertiser
 *
 *  Created by damian on 10/10/10.
 *  Copyright 2010 frey damian@frey.co.nz. All rights reserved.
 *
 */

#pragma once


#include "guiBaseObject.h"
#include "guiColor.h"
#include "simpleColor.h"
#include "guiValue.h"

class guiTypeLabel : public guiBaseObject{
	
public:
	
	//------------------------------------------------
	void setup(string text );
	void setText( string new_text );
	void render();
	
};
