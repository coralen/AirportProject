#ifndef _FLIGHT_H
#define _FLIGHT_H

#include "Helper.h"
#include "AirportManager.h"
#include "Plane.h"
#include "Date.h"

typedef struct {
	char sCode[IATA + 1];
	char dCode[IATA + 1];
	Plane plane;
	Date date;
} Flight;

int isFlightFromSourceAirport(const Flight* pFlight, const char* srcCode);
int isFlightToDestAirport(const Flight* pFlight, const char* dstCode);
int isPlaneTypeInFlight(const Flight* pFlight, const PlaneType type);
void initFlight(Flight* pFlight, const Plane* pPlane, const AirportManager* pAirportManager);
void printFlight(const Flight* pFlight);
void freeFlight(Flight* pFlight);

#endif
