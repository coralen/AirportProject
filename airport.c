#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../include/airport.h"


int initAirport(Airport* pAirport)
{


}


int isSameAirport(Airport* airportPtr1, Airport* airportPtr2)
{
    for (int i = 0; i < IATA; i++){
        if (airportPtr1->code[i] == airportPtr2->code[i])
            return 0;
    }return 1;
}

int isAirportCode(Airport* airportPtr, const char* code)
{
    for (int i = 0; i < IATA; i++){
        if (airportPtr->code[i] != code[i])
            return 0;
    }return 1;
}

void printAirport(Airport* pAirport)
{
    printf("Airport name:");
    printWithUnderscores((const char *) pAirport->name);

    printf("A                  Country: %s", pAirport->country);

    printf("                 Code:%c%c%c", pAirport->code[0], pAirport->code[1], pAirport->code[2]);

}
void printWithUnderscores(const char *input)
{
        while (*input != '\0') {
            printf("%c_", *input);
            input++;
        }
        printf("\n");
}

void free(){

}
