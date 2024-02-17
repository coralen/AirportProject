#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Plane.h"
#include "Helper.h"

#define MIN_SERIAL 1
#define MAX_SERIAL 9999
#define MIN_TYPE 0
#define MAX_TYPE 2


int initPlane(Plane* pPlane, const Plane* planeArr, const int planeCount)
{
	int serielNumber;

	do {
		printf("Enter plane serial number - between 1 to 9999\n");
		scanf("%d", &serielNumber);
		printf("\n\n");
	} while (serielNumber < MIN_SERIAL || serielNumber > MAX_SERIAL || isPlaneExist(pPlane, planeArr, planeCount));

	pPlane->serielNumber = serielNumber;

	getPlaneType(pPlane);
	if (!pPlane) return 0; // Allocation did not work
	return 1;
}

int isPlaneExist(Plane* pPlane, const Plane* planeArr, const int planeCount)
{
	for (int i = 0; i < planeCount; i++)
		if (planeArr[i].serielNumber == pPlane->serielNumber) return 1;
	return 0;
}

void getPlaneType(Plane* pPlane)
{
	int choice;

	do {
		printf("Please enter one of the following types\n0 for Commercial\n1 for Cargo\n2 for Military\n");
		scanf("%d", &choice);
		printf("\n");
	} while (choice < MIN_TYPE || choice > MAX_TYPE);

	if (!(pPlane->type = (PlaneType*)malloc(sizeof(PlaneType)))) return;
	*pPlane->type = (PlaneType)choice;
}

void printPlane(const Plane* pPlane)
{
	printf("Plane: serial number:%d, type %s", pPlane->serielNumber, stringPlaneType(pPlane->type));
}

char* stringPlaneType(const PlaneType* type)
{
	switch (*type) {
	case COMMERCIAL:
		return "Commercial";
		break;
	case CARGO:
		return "Cargo";
		break;
	case MILITARY:
		return "Military";
		break;
	default:
		return "";
		break;
	}
}


void freePlane(Plane* pPlane)
{
	free(pPlane->type);
	free(pPlane);	
}
