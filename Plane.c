#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Plane.h"
#include "Helper.h"

#define MIN_SERIAL 1
#define MAX_SERIAL 9999
#define MIN_TYPE 0
#define MAX_TYPE 2


int initPlane(Plane* pPlane)
{

	getSerialNumber(pPlane);
	getPlaneType(pPlane);
	if (!pPlane->planeType) return 0; // Allocation did not work
	return 1;

}

void getSerialNumber(Plane* pPlane)
{
	do {
		printf("Enter plane serial number - between 1 to 9999");
		scanf("%d", pPlane->serielNumber);
	} while (pPlane->serielNumber < MIN_SERIAL || pPlane->serielNumber > MAX_SERIAL);
}

void getPlaneType(Plane* pPlane)
{
	int planeType;
	char* planeTypes[] = { "Commercial :", "Cargo :", "Military :" };

	do {
		printf("Please enter one of the following types\n0 for Commercial\n1 for Cargo\n2 for Military\n");
		scanf("%d", &planeType);
	} while (planeType < MIN_TYPE || planeType > MAX_TYPE);

	pPlane->planeType = realloc(pPlane->planeType, strlen(planeType) + 1);
	if (!pPlane->planeType) return;
	pPlane->planeType = planeTypes[planeType];
}

void printPlane(Plane* pPlane)
{
	printf("Plane: serial number:%d, type %s", pPlane->serielNumber, pPlane->planeType);
}

void freePlane(Plane* pPlane)
{
	free(pPlane->planeType);
}