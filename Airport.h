#ifndef _AIRPORT_H
#define _AIRPORT_H

#define IATA 3

typedef struct {
	char* name;
	char* country;
	char code[IATA];
} Airport;

void initAirport(Airport* pAirport);
void printAirport(const Airport* pAirport);
void printWithUnderscores(const char* input);
int isSameAirport(const Airport* pAirport, const Airport* ptrAirport);
int isAirportCode(const Airport* pAirport, const char* code);
int isCodeValid(const char* code);


#endif
