#include <stdio.h>
#include <stdlib.h>

#include "flight.h"

int initFlight(Flight* pFlight)
{

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
