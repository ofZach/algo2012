/*
 *  guiCallbackValue.h
 *  ofxControlPanelDemo
 *
 *  Created by theo on 31/03/2010.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

typedef enum{
	CB_VALUE_NOT_SET,
	CB_VALUE_INT,
	CB_VALUE_FLOAT,
	CB_VALUE_STRING
}guiCBValueType;

class cbValue{
	public:
		cbValue(){
			valF = 0.0f;
			valI = 0;
			valueType = CB_VALUE_NOT_SET;
		}
		
		void setValue(float val){
			valF = val;
			valueType = CB_VALUE_FLOAT;
		}

		void setValue(int val){
			valI = val;
			valueType = CB_VALUE_INT;
		}

		void setValue(string val){
			valS = val;
			valueType = CB_VALUE_STRING;
		}
		
		guiCBValueType getType(){
			return valueType;
		}
		
		float getFloat(){
			if( valueType == CB_VALUE_FLOAT ){
				return valF;
			}else if( valueType == CB_VALUE_INT ){
				return (float)valI;
			}
			return 0.0f;
		}
		
		int getInt(){
			if( valueType == CB_VALUE_INT ){
				return valI;
			}else if( valueType == CB_VALUE_FLOAT ){
				return (int)valF;
			}
			return 0;
		}
		
		string getString(){
			if( valueType == CB_VALUE_STRING ){
				return valS;
			}else if( valueType == CB_VALUE_FLOAT ){
				return ofToString(valF);
			}else{
				return ofToString(valI);
			}
			return "";
		}
				
		guiCBValueType valueType;
		float   valF;
		int     valI;
		string  valS;
};

class guiCallbackData{
	public:
	
		void setup(string xmlNameIn, string displayNameIn){
			xmlName	    = xmlNameIn;
			displayName = displayNameIn;
		}
		
		void addValueF(float val){
			values.push_back(cbValue());
			values.back().setValue(val);
		}

		void addValueI(int val){
			values.push_back(cbValue());
			values.back().setValue(val);
		}

		void addValueS(string val){
			values.push_back(cbValue());
			values.back().setValue(val);
		}
		
		bool isElement(string nameToMatch){
			if( nameToMatch == xmlName || nameToMatch == displayName) return true;
			return false;
		}
		
		string getXmlName(){
			return xmlName;
		}
		
		string getDisplayName(){
			return displayName;
		}
				
		int getNumValues(){
			return values.size();
		}
		
		float getFloat(int which){
			if( which < values.size() ){
				return values[which].getFloat();
			}
			return 0.0;	
		}

		int getInt(int which){
			if( which < values.size() ){
				return values[which].getInt();
			}
			return 0;
		}
		
		guiCBValueType getType(int which){
			if( which < values.size() ){
				return values[which].getType();
			}
			return CB_VALUE_NOT_SET;
		}

		string getString(int which){
			if( which < values.size() ){
				return values[which].getString();
			}
			return "";
		}
		
		protected:
		
		string displayName;
		string xmlName;
		vector <cbValue> values;	
};


class guiCallbackValue{
	public:
		guiCallbackData val;
};

