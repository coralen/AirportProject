#ifndef _FLIGHT_H
#define _FLIGHT_H

#include "plane.h"
#include "date.h"
#include "utilities.h"

typedef struct
{
	char sourceCode;
	char destCode;
	Plane Plane;
	Date date;
} Flight;

void getAttributes();
void printFlight();
int isFlightFromSourceAirport();
int isFlightToDestAirport();
int isPlaneTypeInFlight();

#endif