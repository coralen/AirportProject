#include <stdio.h>
#include <stdlib.h>

#include "../include/airport.h"

char* getAirportName()
{
	char* name;
	name = (char*)malloc(MAX_LENGTH * sizeof(char));

}
void getAttributes()
{
	
}

void printAirport()
{

}

int isSameAirport(Airport* airportPtr1, Airport* airportPtr2)
{
    if (*(airportPtr1->code)==*(airportPtr2->code)) {
        return 1;
    }else return 0;
}

int isAirportCode(Airport* airportPtr, char code)
{
	if (*(airportPtr->code)== code) {
        return 1;
    }else return 0;
}
