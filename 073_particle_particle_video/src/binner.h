
#include <stdio.h>

#ifndef 	BINNER_H
#define 	BINNER_H

void					setupBins(int w, int h, int nDivisionsX, int nDivisionsY);	// do this once! 
void 			computeBinPosition(int xpos, int ypos, unsigned int *bitFlag, unsigned int *bitFlag2);

//------------------------------------------------------


#endif