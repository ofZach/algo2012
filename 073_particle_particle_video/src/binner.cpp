#include "binner.h"



//------------------------------------------------------
int 			nBinDivisionsW; // must be an odd number
int 			nBinDivisionsH; // must be an odd number
float 			binDivisionWidth;
float			binDivisionWidthInv;
float 			binDivisionSubBoundaryMinW, binDivisionSubBoundaryMaxW;
float 			binDivisionHeight;
float 			binDivisionHeightInv;
float 			binDivisionSubBoundaryMinH, binDivisionSubBoundaryMaxH;

void computeBinPosition(int xpos, int ypos, unsigned int *bitFlagW, unsigned int *bitFlagH){
	int posBin1, posBin2;
	*bitFlagW = 0x00000000;
	*bitFlagH = 0x00000000;
	
	
	if (xpos < 0) xpos = 0;
	if (ypos < 0) ypos = 0;
	if (xpos > binDivisionWidth*nBinDivisionsW) xpos = binDivisionWidth*nBinDivisionsW;
	if (ypos > binDivisionHeight*nBinDivisionsH) ypos = binDivisionHeight*nBinDivisionsH;
	
	// compute for X
	posBin1 = (int)((float)xpos * binDivisionWidthInv);
	*bitFlagW |= (0x00000001 << (posBin1 * 2));
	
	if (xpos > binDivisionSubBoundaryMinW && xpos < binDivisionSubBoundaryMaxW){
		posBin2 = (int)((float)(xpos - binDivisionSubBoundaryMinW) * binDivisionWidthInv);
		*bitFlagW |=  (0x00000001 << (1 + posBin2 * 2));
	}
	
	// compute for Y
	posBin1 = (int)((float)ypos * binDivisionHeightInv);
	*bitFlagH |= (0x00000001 << ( posBin1 * 2));
	
	if (ypos > binDivisionSubBoundaryMinH && ypos < binDivisionSubBoundaryMaxH){
		posBin2 = (int)((float)(ypos - binDivisionSubBoundaryMinH) * binDivisionHeightInv);
		*bitFlagH |=  (0x00000001 << (1 + posBin2 * 2));
	}
}

//-------------------------------------
void setupBins(int w, int h,  int nDivisionsX, int nDivisionsY){

	nBinDivisionsW = nDivisionsX; 
	nBinDivisionsH = nDivisionsY; 

	binDivisionWidth  = w  / (float)nBinDivisionsW;
	binDivisionHeight = h / (float)nBinDivisionsH;
	binDivisionWidthInv  = 1.0f/binDivisionWidth;
	binDivisionHeightInv = 1.0f/binDivisionHeight;

	binDivisionSubBoundaryMinW = binDivisionWidth / 2.0f;
	binDivisionSubBoundaryMaxW = w - binDivisionWidth / 2.0f;

	binDivisionSubBoundaryMinH = binDivisionHeight / 2.0f;
	binDivisionSubBoundaryMaxH = h - binDivisionHeight / 2.0f;

}

//-------------------------------------
