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
	char code[MAX_STRING];

	pFlight->plane = *pPlane;
	//printf("there are %d airports\n", pAirportManager->airportCount);
	//printAirports(pAirportManager);

	// Select origin airport
	printf("Enter code of origin airport:");
	do {
		scanf("%s", &code);
		printf("\n");
		if (findAirportByCode(pAirportManager, code)) validSrc = 1;
		else printf("No airport with this code - try again\n");
	} while (!validSrc);
	strcpy(pFlight->sCode, code);

	// Select destination airport
	// coral: there is a problem here. it accepts bad codes.
	do {
		printf("Enter code of destination airport:");
		scanf("%s", &code);
		if (isFlightFromSourceAirport(pFlight, code)) printf("Same origin and destination airport\n");
		else {
			if (findAirportByCode(pAirportManager, code)) validDst = 1;
			else printf("No airport with this code - try again\n");
		}
	} while (!validDst);
	strcpy(pFlight->dCode, code);

	getCorrectDate(&pFlight->date);

}

int isFlightFromSourceAirport(const Flight* pFlight, const char* sCode)
{
	if (!strcmp(pFlight->sCode ,sCode)) return 1;
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
	printf(" ");
	printPlane(&pFlight->plane);
	printf("\n");
}

void freeFlight(Flight* pFlight)
{
	free(pFlight);
}

