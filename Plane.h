#ifndef _PLANE_H
#define _PLANE_H

typedef struct
{
	char* planeType;
	int serielNumber;
} Plane;

int initPlane(Plane* pPlane);
void printPlane(const Plane* pPlane);
void getSerialNumber(Plane* pPlane);
void getPlaneType(Plane* pPlane);

#endif