#include <stdio.h>
#include <stdlib.h>

#include "airline.h"
#include "airportManager.h"
#include "plane.h"
#include "helper.h"

int initAirline(Airline *pAirline)
{
	getAirlineName(pAirline);
	if (!pAirline->airlineName) // Allocation did not work
		return 0;
	pAirline->flightCount = 0;
	pAirline->planeCount = 0;
	pAirline->flights = NULL;
	pAirline->planes = NULL;
	return 1;
}

void getAirlineName(Airline* pAirline)
{
	char airlineName[MAX_STRING];
	printf("Enter Airline name");
	scanf("%s", &airlineName);
	pAirline->airlineName = malloc(strlen(airlineName) + 1);
	if (!pAirline->airlineName) return;
	strcpy(pAirline->airlineName, airlineName);
}

int addFlight(Airline* pAirline, AirportManager* pAirportManager)
{
	Flight* pFlight;
	int serielNumber;

	if (!isPossibleFlight) return 0;

	initFlight(&pFlight);
	getPlaneForFlight(pAirline, &pFlight);
	getSrcAndDstForFlight(pAirportManager, &pFlight);
	initDate(&pFlight->date);

	// Allocate memory and add new flight
	pAirline->flightCount++;
	if (!allocateFlight(&pAirline, &pFlight)) return 0;
	pAirline->flights[pAirline->flightCount - 1] = pFlight;
	
	return 1;
}

int addPlane(Airline* pAirline)
{
	Plane* pPlane;

	initPlane(pPlane);
	
	pAirline->planeCount++;
	pAirline->planes = realloc(pAirline->planes, pAirline->planeCount * sizeof(Plane));
	if (!pAirline->planes)
	{
		pAirline->planeCount--;
		freePlane(pPlane);
		return 0;
	}
	pAirline->planes[pAirline->planeCount - 1] = *pPlane;

	return 1;
}

void doPrintFlightsWithPlaneType(Airline* pAirline)
{
	char* planeType;
	Plane* pPlane = NULL;
	int found = 0;

	getPlaneType(&planeType);
	printf("Flights with plane type %s\n", planeType);

	for (int i = 0; i < pAirline->planeCount; i++)
	{
		*pPlane = pAirline->planes[i];
		if (pPlane->planeType == planeType)
		{
			printFlight(&pAirline->planes[i]);
			found = 1;
		}
	}

	if (!found) printf("Sorry - could not find a flight with plane type %s\n", planeType);
}

Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount)
{
	for (int i = 0; i < planeCount; i++)
		if (pAirline->planes[i].serielNumber == serielNumber) return &pAirline->planes[i];
	return NULL;
}

void getPlaneForFlight(const Airline* pAirline, Flight* pFlight)
{
	int serielNumber, validSerial = 0;
	Plane* pPlane;

	init(pPlane);
	printf("Choose a plane from list, type its serial Number\n");
	printPlanes(pAirline, pAirline->planeCount);

	while (validSerial)
	{
		scanf("%d", serielNumber);
		pPlane = findPlaneBySerialNumber(pAirline, serielNumber, pAirline->planeCount);
		if (pPlane != NULL) validSerial = 1;
	}
	pFlight->plane = *pPlane;
	
}

void getSrcAndDstForFlight(const AirportManager* pAirportManager, Flight* pFlight)
{
	int validSrc = 0, validDst = 0;
	printf("there are %d airports", pAirportManager->airportCount);
	printAirports(pAirportManager);

	// Select origin airport
	printf("Enter code of origin airport :");
	while (validSrc)
	{
		scanf("%s", pFlight->srcCode);
		if (findAirportByCode(pAirportManager, pFlight->srcCode) != NULL) validSrc = 1;
		else printf("No airport with this code - try again");
	}

	// Select destination airport
	printf("Enter code of destination airport :");
	while (validDst)
	{
		scanf("%d", pFlight->dstCode);
		if (findAirportByCode(pAirportManager, pFlight->dstCode) != NULL) validDst = 1;
		else printf("No airport with this code - try again");
	}

}

int isPossibleFlight(Airline* pAirline, AirportManager* pAirportManager)
{
	if (pAirportManager->airportCount < 2)
	{
		printf("There are not enough airport to set a flight\n");
		return 0;
	}

	if (!pAirline->planes)
	{
		printf("There is no plane in company\n");
		return 0;
	}

	return 1;
}

int allocateFlight(Airline* pAirline, Flight* pFlight)
{
	pAirline->flights = realloc(pAirline->flights, pAirline->flightCount * sizeof(Flight));
	if (!pAirline->flights)
	{
		freeFlight(pFlight);
		pAirline->flightCount--;
		return 0;
	}
	return 1;
}

void printAirline(const Airline* pAirline)
{
	printf("Airline %s\n", pAirline->airlineName);
	printf(" -------- Has %d planes", pAirline->planeCount);
	printPlanes(pAirline);
	printf(" -------- Has %d flights", pAirline->flightCount);
	printFlight(pAirline);
}

void printAirports(const AirportManager* pAirportManager)
{
	for (int i = 0; i < pAirportManager->airportCount; i++)
		printAirport(pAirportManager->airports[i]);
}

void printFlights(const Airline* pAirline)
{
	for (int i = 0; i < pAirline->flightCount; i++)
		printFlight(pAirline->flights[i]);
}

void printPlanes(const Airline* pAirline)
{
	for (int i = 0; i < pAirline->planeCount; i++)
		printPlane(&pAirline->planes[i]);
}

void freeAirline(Airline* pAirline)
{
	free(pAirline->airlineName);
	for (int i = 0; i < pAirline->flightCount; i++)
		freeFlight(pAirline->flights[i]);
	for (int j = 0; j < pAirline->planeCount; j++)
		freePlane(&pAirline->planes[j]);
}