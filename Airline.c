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
	Plane* pPlane;
	int serielNumber;

	if (!isPossibleFlight) return 0;

	// Allocate memory and add a new flight
	pAirline->flightArr = (Flight*)realloc(pAirline->flightArr, (pAirline->flightCount + 1) * sizeof(Flight));
	if (!pAirline->flightArr) return 0;

	pAirline->flightCount++;
	pFlight = pAirline->flightArr[pAirline->flightCount - 1];
	getPlaneForFlight(pAirline, &pPlane);
	initFlight(&pFlight, pPlane, pAirportManager);

	return 1;
}

int addPlane(Airline* pAirline)
{
	Plane* pPlane = NULL;

	initPlane(pPlane, pAirline->planeArr, pAirline->planeCount);
	if (isSamePlane(pAirline, pPlane)) return 0;

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

int isSamePlane(const Airline* pAirline, const Plane* pPlane)
{
	for (int i = 0; i < pAirline->planeCount; i++)
		if (pAirline->planeArr[i].serielNumber == pPlane->serielNumber) return 0;
	return 1;
}

void doPrintFlightsWithPlaneType(Airline* pAirline)
{
	PlaneType type;
	int found = 0;

	getPlaneType(&type);
	printf("Flights with plane type %s\n", type);

	for (int i = 0; i < pAirline->flightCount; i++)
	{
		if (isPlaneTypeInFlight(pAirline->flightArr[i], type))
		{
			printFlight(&pAirline->flightArr[i]);
			found = 1;
		}
	}

	if (!found) printf("Sorry - could not find a flight with plane type %s\n", type);
}

Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount)
{
	for (int i = 0; i < planeCount; i++)
		if (pAirline->planeArr[i].serielNumber == serielNumber) return &pAirline->planeArr[i];
	return NULL;
}

void getPlaneForFlight(const Airline* pAirline, Plane* pPlane)
{
	int serielNumber = 0;

	printf("Choose a plane from list, type its serial Number\n");
	printPlaneArr(pAirline, pAirline->planeCount);

	do {
		scanf("%d", serielNumber);
		pPlane = findPlaneBySerialNumber(pAirline, serielNumber, pAirline->planeCount);
	} while (&pPlane == NULL);
	
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

void printAirline(const Airline* pAirline)
{
	printf("Airline %s\n", pAirline->name);
	printf(" -------- Has %d planes", pAirline->planeCount);
	printPlaneArr(pAirline);
	printf(" -------- Has %d flights", pAirline->flightCount);
	printFlightArr(pAirline);
}

void printAirportArr(const AirportManager* pAirportManager)
{
	for (int i = 0; i < pAirportManager->airportCount; i++)
		printAirport(pAirportManager->airportArr[i]);
}

void printFlightArr(const Airline* pAirline)
{
	for (int i = 0; i < pAirline->flightCount; i++)
		printFlight(pAirline->flightArr[i]);
}

void printPlaneArr(const Airline* pAirline)
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
