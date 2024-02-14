#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Airline.h"
#include "AirportManager.h"
#include "Plane.h"
#include "Helper.h"

int initAirline(Airline *pAirline)
{
	char name[MAX_STRING];

	// Scan airline name
	printf("Enter Airline name");
	scanf("%s", &name);
	pAirline->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	if (!pAirline->name) return 0; // Allocation did not work
	strcpy(pAirline->name, name);

	pAirline->flightCount = 0;
	pAirline->planeCount = 0;
	pAirline->flightArr = NULL;
	pAirline->planeArr = NULL;
	return 1;
}

int addFlight(Airline* pAirline, AirportManager* pAirportManager)
{
	Flight* pFlight;
	int serielNumber;

	if (!isPossibleFlight) return 0;

	getPlaneForFlight(pAirline, &pFlight);
	getSrcAndDstForFlight(pAirportManager, &pFlight);
	initDate(&pFlight->date);

	// Allocate memory and add new flight
	pAirline->flightCount++;
	if (!allocateFlight(&pAirline, &pFlight)) return 0;
	pAirline->flightArr[pAirline->flightCount - 1] = pFlight;
	
	return 1;
}

int addPlane(Airline* pAirline)
{
	Plane* pPlane = NULL;

	initPlane(pPlane);
	if (!comparePlanes(pAirline, pPlane)) return 0;

	pAirline->planeCount++;
	pAirline->planeArr = realloc(pAirline->planeArr, pAirline->planeCount * sizeof(Plane));
	if (!pAirline->planeArr)
	{
		pAirline->planeCount--;
		freePlane(pPlane);
		return 0;
	}
	pAirline->planeArr[pAirline->planeCount - 1] = *pPlane;

	return 1;
}

int comparePlanes(const Airline* pAirline, const Plane* pPlane)
{
	for (int i = 0; i < pAirline->planeCount; i++)
		if (pAirline->planeArr[i].serielNumber == pPlane->serielNumber) return 0;
	return 1;
}

void doPrintFlightsWithPlaneType(Airline* pAirline)
{
	char* planeType;
	int found = 0;

	getPlaneType(&planeType);
	printf("Flights with plane type %s\n", planeType);

	for (int i = 0; i < pAirline->planeCount; i++)
	{
		if (pAirline->planeArr[i].planeType == planeType)
		{
			printFlight(&pAirline->planeArr[i]);
			found = 1;
		}
	}

	if (!found) printf("Sorry - could not find a flight with plane type %s\n", planeType);
}

Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount)
{
	for (int i = 0; i < planeCount; i++)
		if (pAirline->planeArr[i].serielNumber == serielNumber) return &pAirline->planeArr[i];
	return NULL;
}

void getPlaneForFlight(const Airline* pAirline, Flight* pFlight)
{
	int serielNumber = 0;

	printf("Choose a plane from list, type its serial Number\n");
	printPlanesArr(pAirline, pAirline->planeCount);

	do {
		scanf("%d", serielNumber);
		pFlight->plane = *findPlaneBySerialNumber(pAirline, serielNumber, pAirline->planeCount);
	} while (&pFlight->plane == NULL);
	
}

void getSrcAndDstForFlight(const AirportManager* pAirportManager, Flight* pFlight)
{
	int validSrc = 0, validDst = 0;
	printf("there are %d airports", pAirportManager->airportCount);
	printAirportsArr(pAirportManager);

	// Select origin airport
	printf("Enter code of origin airport :");
	do {
		scanf("%s", pFlight->srcCode);
		if (findAirportByCode(pAirportManager, pFlight->srcCode) != NULL) validSrc = 1;
		else printf("No airport with this code - try again");
	} while (!validSrc);

	// Select destination airport
	printf("Enter code of destination airport :");
	do {
		scanf("%d", pFlight->dstCode);
		if (findAirportByCode(pAirportManager, pFlight->dstCode) != NULL) validDst = 1;
		else printf("No airport with this code - try again");
	} while (!validDst);

}

int isPossibleFlight(Airline* pAirline, AirportManager* pAirportManager)
{
	if (pAirportManager->airportCount < 2)
	{
		printf("There are not enough airport to set a flight\n");
		return 0;
	}

	if (!pAirline->planeArr)
	{
		printf("There is no plane in company\n");
		return 0;
	}

	return 1;
}

int allocateFlight(Airline* pAirline, Flight* pFlight)
{
	pAirline->flightArr = realloc(pAirline->flightArr, pAirline->flightCount * sizeof(Flight));
	if (!pAirline->flightArr)
	{
		freeFlight(pFlight);
		pAirline->flightCount--;
		return 0;
	}
	return 1;
}

void printAirline(const Airline* pAirline)
{
	printf("Airline %s\n", pAirline->name);
	printf(" -------- Has %d planes", pAirline->planeCount);
	printPlanesArr(pAirline);
	printf(" -------- Has %d flights", pAirline->flightCount);
	printFlightsArr(pAirline);
}

void printAirportsArr(const AirportManager* pAirportManager)
{
	for (int i = 0; i < pAirportManager->airportCount; i++)
		printAirport(pAirportManager->airports[i]);
}

void printFlightsArr(const Airline* pAirline)
{
	for (int i = 0; i < pAirline->flightCount; i++)
		printFlight(pAirline->flightArr[i]);
}

void printPlanesArr(const Airline* pAirline)
{
	for (int i = 0; i < pAirline->planeCount; i++)
		printPlane(&pAirline->planeArr[i]);
}

void freeCompany(Airline* pAirline)
{
	free(pAirline->name);
	for (int i = 0; i < pAirline->flightCount; i++)
		freeFlight(pAirline->flightArr[i]);
	for (int j = 0; j < pAirline->planeCount; j++)
		freePlane(&pAirline->planeArr[j]);
}