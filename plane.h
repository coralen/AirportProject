#ifndef _PLANE_H
#define _PLANE_H

#include "utilities.h"

#define PLANE_TYPE_MAX 2
#define PLANE_TYPE_MIN 0

typedef enum { COMMERCIAL, CARGO, MILIARY } PlaneType;

#define MAX_SERIEL_NUMBER 9999
#define MIN_SERIEL_NUMBER 1

typedef struct
{
    char* planeType;
	int serielNumber;
} Plane;

void getAttributes();
void printPlane();

#endif