#ifndef _FLIGHT_H
#define _FLIGHT_H

#include "Plane.h"
#include "Date.h"

#define CODE 3

typedef struct {
	char srcCode[3];
	char dstCode[3];
	Plane plane;
	Date date;
} Flight;

void initFlight(Flight* pFlight, Plane* pPlane, const AirportManager* pManager);
int isFlightFromSourceAirport(Flight* pFlight, char* srcCode);
int isFlightToDestAirport(Flight* pFlight, char* dstCode);
int isPlaneTypeInFlight(Flight* pFlight, char* planeType);
void printFlight(const Flight* pFlight);
void freeFlight(Flight* pFlight);

#endif
