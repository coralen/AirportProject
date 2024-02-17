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
	char input[MAX_STRING];

	do {
		printf("Enter plane serial number - between 1 to 9999\n");
		scanf("%s", input);
		sscanf(input, "%d", &pPlane->serielNumber);
	} while (pPlane->serielNumber && (pPlane->serielNumber < MIN_SERIAL || pPlane->serielNumber > MAX_SERIAL || isPlaneExist(pPlane, planeArr, planeCount)));

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

void getSerialNumber(Plane* pPlane)
{
	do {
		printf("Enter plane serial number - between 1 to 9999");
		scanf("%d", &pPlane->serielNumber);
	} while (pPlane->serielNumber < MIN_SERIAL || pPlane->serielNumber > MAX_SERIAL);
}

void getPlaneType(Plane* pPlane)
{
	int choice;

	do {
		printf("Please enter one of the following types\n0 for Commercial\n1 for Cargo\n2 for Military\n");
		scanf("%d", &choice);
	} while (choice < MIN_TYPE || choice > MAX_TYPE);

	if (!(pPlane->type = (PlaneType*)malloc(sizeof(PlaneType)))) return;
	
	// Convert the integer choice to PlaneType enum value
	switch (choice) {
	case 0:
		*pPlane->type = COMMERCIAL;
		break;
	case 1:
		*pPlane->type = CARGO;
		break;
	case 2:
		*pPlane->type = MILITARY;
		break;

	}
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
