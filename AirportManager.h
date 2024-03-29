#ifndef _AIRPORTMANAGER_H
#define _AIRPORTMANAGER_H

#include "Airport.h"

typedef struct {
	Airport** airportArr;
	int airportCount;
} AirportManager;


int initManager(AirportManager* pAirportManager);
int addAirport(AirportManager* pAirportManager);
int isCodeValid(const char* code);
int isSameCode(const char* code1, const char* code2);
void printAirports(const AirportManager* pAirportManager);
void freeManager(AirportManager* pAirportManager);
Airport* findAirportByCode(const AirportManager* pAirportManager, const char* code);


#endif
