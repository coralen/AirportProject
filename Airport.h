#ifndef _AIRPORT_H
#define _AIRPORT_H

#include "Helper.h"

typedef struct {
	char* name;
	char* country;
	char code[
		+ 1];
	int planeCount;
} Airport;

int isSameAirport(const Airport* airportPtr1, const Airport* airportPtr2);
int isAirportCode(const Airport* pAirport, const char* code);
int isCodeValid(const char* code);
void initAirportNoCode(Airport* pAirport);
void getAirportCode(char* code);
void getAirportName(Airport* pAirport);
void getAirportCountry(Airport* pAirport);
void printAirport(const Airport* pAirport);
void printWithUnderscores(const char* input);
void freeAirport(Airport* pAirport);


#endif
