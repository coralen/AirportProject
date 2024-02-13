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

void initAirline(Airline* pAirline);
void doPrintFlightsWithPlaneType(Airline* pAirline);
void getPlaneType(char* planeType);
void getPlaneForFlight(const Airline* pAirline, Flight* pFlight);
void getSrcAndDstForFlight(const AirportManager* pAirportManager, Flight* pFlight);
void printAirline(const Airline* pAirline);
void printAirports(const AirportManager* pAirportManager);
void printFlights(const Airline* pAirline);
void printPlanes(const Airline* pAirline);
int addFlight(Airline* pAirline, AirportManager* pAirportManager);
int addPlane(Airline* pAirline);
int isPossibleFlight(Airline* pAirline, AirportManager* pAirportManager);
int allocateFlight(Airline* pAirline, Flight* pFlight);
Plane* planeBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount);


#endif