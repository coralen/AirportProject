#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Airline.h"
#include "AirportManager.h"
#include "Plane.h"
#include "Helper.h"

int initAirline(Airline* pAirline)
{
	char name[MAX_STRING];

	printf(" Enter Airline name");
	scanf(" %[^\n]", &name);
	printf("\n");

	if (!(pAirline->name = (char*)malloc((strlen(name) + 1) * sizeof(char)))) return 0;
	strcpy(pAirline->name, name);

	pAirline->flightCount = 0;
	pAirline->planeCount = 0;
	pAirline->flightArr = NULL;
	pAirline->planeArr = NULL;
	return 1;
}

int addFlight(Airline* pAirline, AirportManager* pAirportManager)
{
	Plane* pPlane = NULL;

	if (!isPossibleFlight(pAirline, pAirportManager)) return 0;

	if (!(pAirline->flightArr = (Flight**)realloc(pAirline->flightArr, (pAirline->flightCount + 1) * sizeof(Flight*)))) return 0;
	if (!(pAirline->flightArr[pAirline->flightCount] = (Flight*)malloc(sizeof(Flight)))) return 0;
	if (!(pPlane = (Plane*)malloc(sizeof(Plane)))) return 0; 

	pPlane = getPlaneForFlight(pAirline, pPlane);
	initFlight(pAirline->flightArr[pAirline->flightCount], pPlane, pAirportManager);
	pAirline->flightCount++;

	freePlane(pPlane);

	return 1;
}

int addPlane(Airline* pAirline)
{

	if (!(pAirline->planeArr = (Plane*)realloc(pAirline->planeArr, (pAirline->planeCount + 1) * sizeof(Plane)))) return 0;

	if (!(initPlane(&pAirline->planeArr[pAirline->planeCount], pAirline->planeArr, pAirline->planeCount))) return 0;

	if (isSamePlane(pAirline, &pAirline->planeArr[pAirline->planeCount])) return 0;
	pAirline->planeCount++;

	return 1;
}

int isSamePlane(const Airline* pAirline, const Plane* pPlane)
{
	for (int i = 0; i < pAirline->planeCount; i++)
	{
		if (pAirline->planeArr[i].serielNumber == pPlane->serielNumber)
			return 1;
	}
	return 0;
}

void doPrintFlightsWithPlaneType(Airline* pAirline)
{
	Plane* pPlane = NULL;
	int found = 0;

	getPlaneType(pPlane);
	printf("Flights with plane type %s\n", stringPlaneType(pPlane->type));

	for (int i = 0; i < pAirline->flightCount; i++)
	{
		if (isPlaneTypeInFlight(pAirline->flightArr[i], pPlane->type))
		{
			printFlight(pAirline->flightArr[i]);
			found = 1;
		}
	}

	if (!found) printf("Sorry - could not find a flight with plane type %s\n", stringPlaneType(pPlane->type));
}

Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount)
{
	for (int i = 0; i < planeCount; i++)
		if (pAirline->planeArr[i].serielNumber == serielNumber) return &pAirline->planeArr[i];
	return NULL;
}

Plane* getPlaneForFlight(const Airline* pAirline, Plane* pPlane)
{
	int serielNumber = 0;

	printf("Choose a plane from list, type its serial Number\n");
	printPlanesArr(pAirline->planeArr, pAirline->planeCount);

	do {
		scanf("%d", &serielNumber);
		pPlane = findPlaneBySerialNumber(pAirline, serielNumber, pAirline->planeCount);
		if (!pPlane) printf("No plane with that serial number! Try again!\n");
	} while (!pPlane);

	return pPlane;
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
	printPlanesArr(pAirline->planeArr, pAirline->planeCount);
	printf(" -------- Has %d flights", pAirline->flightCount);
	printFlightsArr(pAirline->flightArr, pAirline->flightCount);
}

void printFlightsArr(Flight** const flightArr, const int flightCount)
{
	for (int i = 0; i < flightCount; i++)
	{
		printFlight(flightArr[i]);
		printf("\n");
	}
}

void printPlanesArr(const Plane* planeArr, const int planeCount)
{
	for (int i = 0; i < planeCount; i++)
	{
		printPlane(&planeArr[i]);
		printf("\n");
	}
}

void freeCompany(Airline* pAirline)
{
	for (int i = 0; i < pAirline->flightCount; i++)
		freeFlight(pAirline->flightArr[i]);
	free(pAirline->flightArr);
	free(pAirline->planeArr);
	free(pAirline->name);
}
