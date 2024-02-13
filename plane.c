#include <stdio.h>
#include <stdlib.h>

#include "plane.h"
#include "helper.h"

void initPlane()
{
	char planeType[MAX_STRING];
}

void printPlane(Plane* pPlane)
{
	printf("Plane: serial number:%d, type %s", pPlane->serielNumber, pPlane->planeType);
}