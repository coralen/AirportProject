#ifndef _AIRPORT_H
#define _AIRPORT_H

#include "utilities.h"

#define IATA 3
#define MAX_LENGTH 100

typedef struct {
	char name;
	char country;
	char code[IATA];
    int countPlanes;
} Airport;

void getAttributes();
void printAirport();
int isSameAirport(Airport* airportPtr1, Airport* airportPtr2); // check by IATA code
int isAirportCode(Airport* airportPtr, char code);

#endif