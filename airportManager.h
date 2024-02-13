#ifndef _AIRPORTMANAGER_H
#define _AIRPORTMANAGER_H

#include "../include/airport.h"
#include "airport.h"
#include "utilities.h"

typedef struct {
	Airport* airports;
    int airportCount;
} AirportManager;

int addAirport(AirportManager* pAirportManager);
int isCodeValid(const char* code);
int initAirportManager(AirportManager* pAirportManager);
void printAirportManager(AirportManager* pAirportManager);
char* findAirportByCode(Airport* airports,char code);
int freeAirportManagar(Airport* airport();

#endif