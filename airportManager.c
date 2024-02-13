#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/airportManager.h"

int initAirportManager(AirportManager* pAirportManager){
    pAirportManager->airportCount=0;
}

int addAirport(AirportManager* pAirportManager)
{
    Airport* pAirport;
    initAirport(pAirport);

    pAirportManager->airportCount++;
    pAirportManager->airports = realloc(pAirportManager->airports, pAirportManager->airportCount * sizeof(Airport));

    if(!pAirportManager->airports) return 0;

    pAirportManager->airports[pAirportManager->airportCount] = *pAirport;

    char code[IATA];
    printf("Enter airport code  - 3 UPPER CASE letters");
    do {
        scanf("%3s", &code);
    } while (!isCodeValid(&code));

    for (int i=0; i<IATA; i++)
    {
        pAirport->code[i] = code[i];
    }

    printf("Enter airport name\n");
    scanf("%s", pAirport->name);

    pAirport->name = malloc(strlen(pAirport->name) + 1);
    strcpy(pAirport->name, pAirport->name);

    printf("Enter airport country");
    scanf("%s", &pAirport->country);

    pAirport->countPlanes=0;
}

int isCodeValid(const char* code)
{
    if (strlen( code) != IATA) {
        printf("Code should be 3 letters.\n");
        return 0;
    }
    for (int i = 0; i < IATA; i++)
    {
        if (!isupper(code[i]))
        {
            printf("Need to be upper case letters.\n");
            return 0;
        }
    }
    return 1;
}

char* findAirportByCode(Airport* airports, char code)
{
    for (int i=0; i< airports->countPlanes;i++) {
        if (airports[i]->code[i] == code[i])
            return &airports->code[i];
    }
}


void printAirportManager(AirportManager* pAirportManager)
{
    printf("there are %d airports\n", pAirportManager->airportCount);
    for (int i=0; i<pAirportManager->airportCount; i++){
        printAirport(&(pAirportManager->airports[i]));
    }
}

int freeAirportManagar(AirportManager* pAirportManager){
    for (int i=0; i < pAirportManager->airportCount; i++){
        for (int j=0; i<)
    }
    return 1;
}