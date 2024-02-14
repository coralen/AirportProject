#ifndef _AIRPORTMANAGER_H
#define _AIRPORTMANAGER_H

#include "Airport.h"

typedef struct {
	Airport** airports;
	int airportCount;
} AirportManager;


int initAirportManager(AirportManager* pAirportManager);
int addAirport(AirportManager* pAirportManager);
int isCodeValid(const char* code);
int compareCodes(char* code1, char* code2, int len);
void printAirportManager(AirportManager* pAirportManager);
void freeAirportManagar(AirportManager* pAirportManager);
char* findAirportByCode(AirportManager* pAirportManager, char* code);


#endif