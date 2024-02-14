#ifndef _AIRLINE_H
#define _AIRLINE_H

#include "AirportManager.h"
#include "Flight.h"
#include "Plane.h"

typedef struct {
	char* name;
	int flightCount;
	int planeCount;
	Flight** flightArr;
	Plane* planeArr;
} Airline;

#include <stdio.h>
#include <stdlib.h>

#include "airline.h"
#include "helper.h"

int initAirline(Airline* pAirline);
int addFlight(Airline* pAirline, AirportManager* pAirportManager);
int addPlane(Airline* pAirline);
int isPossibleFlight(Airline* pAirline, AirportManager* pAirportManager);
int allocateFlight(Airline* pAirline, Flight* pFlight);
void getAirlineName(Airline* pAirline);
void doPrintFlightsWithPlaneType(Airline* pAirline);
void getPlaneForFlight(const Airline* pAirline, Flight* pFlight);
void getSrcAndDstForFlight(const AirportManager* pAirportManager, Flight* pFlight);
void printAirline(const Airline* pAirline);
void printAirportsArr(const AirportManager* pAirportManager);
void printFlightsArr(const Airline* pAirline);
void printPlanesArr(const Airline* pAirline);
void freeCompany(Airline* pAirline);
Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount);


#endif