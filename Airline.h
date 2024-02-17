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


int initAirline(Airline* pAirline);
int addFlight(Airline* pAirline, AirportManager* pAirportManager);
int addPlane(Airline* pAirline);
int isPossibleFlight(Airline* pAirline, AirportManager* pAirportManager);
int allocateFlight(Airline* pAirline, Flight* pFlight);
int isSamePlane(const Airline* pAirline, const Plane* pPlane);
void getAirlineName(Airline* pAirline);
void doPrintFlightsWithPlaneType(Airline* pAirline);
Plane* getPlaneForFlight(const Airline* pAirline, Plane* pPlane);
void getSrcAndDstForFlight(const AirportManager* pAirportManager, Flight* pFlight);
void printAirline(const Airline* pAirline);
void printFlightsArr(Flight** const flightArr, const int flightCount);
void printPlanesArr(const Plane* planeArr, const int planeCount);
void freeCompany(Airline* pAirline);
Plane* findPlaneBySerialNumber(const Airline* pAirline, const int serielNumber, const int planeCount);


#endif
