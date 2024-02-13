#ifndef _AIRLINE_H
#define _AIRLINE_H

#include "airportManager.h"
#include "flight.h"
#include "plane.h"

typedef struct {
	char* airlineName;
	int flightCount;
	int planeCount;
	Flight** flights;
	Plane* planes;
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
void doPrintFlightsWithPlaneType(Airline* pAirline); // in progress
void getPlaneForFlight(const Airline* pAirline, Flight* pFlight);
void getSrcAndDstForFlight(const AirportManager* pAirportManager, Flight* pFlight);
void printAirline(const Airline* pAirline);
void printAirports(const AirportManager* pAirportManager);
void printFlights(const Airline* pAirline);
void printPlanes(const Airline* pAirline);
Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount);


#endif