#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Flight.h"
#include "AirportManager.h"

/* In progress */
void initFlight(Flight* pFlight, Plane* pPlane, const AirportManager* pAirportManager) 
{
	pFlight->plane = *pPlane;
	// Move here the flight validation (now in airline), validation like source and destination.
}


int isFlightFromSourceAirport(Flight* pFlight, char* srcCode)
{
	if (pFlight->srcCode == srcCode) return 1;
	return 0;
}

int isFlightToDestAirport(Flight* pFlight, char* dstCode)
{
	if (pFlight->dstCode == dstCode) return 1;
	return 0;
}

int isPlaneTypeInFlight(Flight* pFlight, char* planeType)
{
	if (pFlight->plane.planeType == planeType) return 1;
	return 0;
}

void printFlight(Flight* pFlight)
{
	printf("Flight From %s To %s  Date: ", pFlight->srcCode, pFlight->dstCode);
	printDate(pFlight->date);
	printPlane(&pFlight->plane);
	printf("\n");
}

void freeFlight(Flight* pFlight)
{
	free(pFlight->srcCode);
	free(pFlight->dstCode);
	freePlane(&pFlight->plane);
	freeDate(&pFlight->date);
}
