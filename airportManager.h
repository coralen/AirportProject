#ifndef _AIRPORTMANAGER_H
#define _AIRPORTMANAGER_H

#include "airport.h"
#include "utilities.h"

typedef struct {
	Airport airports;
	int amount;
} AirportManager;

void getAttributes();
void printAirportManager();
void addAirport(char name, char country, char code[]);
void findAirportByCode(char code);

#endif