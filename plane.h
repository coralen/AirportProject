#ifndef _PLANE_H
#define _PLANE_H

#include "utilities.h"

typedef struct
{
	char planeType;
	int serielNumber; // between 1 and 9999
} Plane;

void getAttributes();
void printPlane();

#endif