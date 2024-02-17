#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Flight.h"
#include "AirportManager.h"
#include "Plane.h"


void initFlight(Flight* pFlight, const Plane* pPlane, const AirportManager* pAirportManager) 
{
	int validSrc = 0, validDst = 0;

	pFlight->plane = *pPlane;
	printf("there are %d airports", pAirportManager->airportCount);
	printAirports(pAirportManager);

	// Select origin airport
	printf("Enter code of origin airport :");
	do {
		scanf("%s", pFlight->sCode);
		if (findAirportByCode(pAirportManager, pFlight->sCode) != NULL) validSrc = 1;
		else printf("No airport with this code - try again");
	} while (!validSrc);

	// Select destination airport
	do {
		printf("Enter code of destination airport :");
		scanf("%d", pFlight->dCode);
		if (isFlightFromSourceAirport(pFlight, pFlight->dCode)) printf("Same origin and destination airport\n");
		else {
			if (findAirportByCode(pAirportManager, pFlight->dCode) != NULL) validDst = 1;
			else printf("No airport with this code - try again");
		}
	} while (!validDst);

	getCorrectDate(&pFlight->date);

}

int isFlightFromSourceAirport(const Flight* pFlight, const char* sCode)
{
	if (strcmp(pFlight->sCode ,sCode)) return 1;
	return 0;
}

int isFlightToDestAirport(const Flight* pFlight, const char* dCode)
{
	if (strcmp(pFlight->dCode, dCode)) return 1;
	return 0;
}

int isPlaneTypeInFlight(const Flight* pFlight, const PlaneType* type)
{
	if (pFlight->plane.type == type) return 1;
	return 0;
}

void printFlight(const Flight* pFlight)
{
	printf("Flight From %s To %s  Date: ", pFlight->sCode, pFlight->dCode);
	printDate(&pFlight->date);
	printPlane(&pFlight->plane);
	printf("\n");
}

void freeFlight(Flight* pFlight)
{
	free(pFlight);
}

