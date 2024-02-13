#ifndef _AIRPORT_H
#define _AIRPORT_H

#include "utilities.h"

#define IATA 3
#define MAX_LENGTH 100

typedef struct {
	char name[MAX_LENGTH];
	char country;
	char code[IATA];
    int countPlanes;
} Airport;

int isCodeValid(const char* code);
int initAirport(Airport* pAirport);
void printAirport();
int isSameAirport(Airport* airportPtr1, Airport* airportPtr2); // check by IATA code
int isAirportCode(Airport* airportPtr, const char* code);
void printWithUnderscores(const char *input);

#endif