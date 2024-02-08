#ifndef _AIRLINE_H
#define _AIRLINE_H

#include "flight.h"
#include "plane.h"
#include "utilities.h"

typedef struct {
	char name;
	int amount;
	Flight flights; //array
	Plane planes; //array
} Airline;

void getAttributes();
void printAirline();
void addFlight(Flight flights);
void addPlane(Plane* plane);
void doPrintFlightsWithPlaneType(char planeType);

#endif