#include <stdio.h>
#include <stdlib.h>

#include "AirportManager.h"
#include "Helper.h"

int initManager(AirportManager* pAirportManager) 
{
    printf("initManager\n");
    
    pAirportManager->airportCount = 0;
    pAirportManager->airportArr = NULL;
    return 1;
}

int addAirport(AirportManager* pAirportManager)
{
    printf("addAirport in manager\n");
    
    Airport* pAirport = NULL;

    pAirportManager->airportArr = (Airport**)realloc(pAirportManager->airportArr, (pAirportManager->airportCount + 1) * sizeof(Airport*));
    if (!pAirportManager->airportArr) return 0;
    pAirportManager->airportCount++;
    pAirport = pAirportManager->airportArr[pAirportManager->airportCount - 1];

printf("almost in do while\n");

    do {
        getAirportCode(pAirport->code);
     //   printf("%s  %d", pAirport->code, 5);
        if (findAirportByCode(pAirportManager, pAirport->code)) printf("This code already in use - enter a different code");
    } while (!findAirportByCode(pAirportManager, pAirport->code));

printf("entering initaiport\n");
    initAirportNoCode(pAirport);

    return 1;
}

Airport* findAirportByCode(const AirportManager* pAirportManager, const char* code) 
{
    for (int i = 0; i < pAirportManager->airportCount; i++) 
        if (isSameCode(pAirportManager->airportArr[i]->code, code)) return pAirportManager->airportArr[i];
    return NULL;
}

int isSameCode(const char* code1, const char* code2)
{
    int countCode = 0;

    for (int i = 0; i < IATA; i++)
        if (code1[i] != code2[i]) countCode++;
    if (countCode == 3) return 1;
    return 0;
}

void printAirportManager(const AirportManager* pAirportManager)
{
    printf("there are %d airports\n", pAirportManager->airportCount);
    for (int i = 0; i < pAirportManager->airportCount; i++) {
        printAirport(pAirportManager->airportArr[i]);
    }
}

void printAirports(const AirportManager* pAirportManager)
{
    for (int i = 0; i < pAirportManager->airportCount; i++)
        printAirport(pAirportManager->airportArr[i]);
}

void freeManager(AirportManager* pAirportManager)
{
    for (int i = 0; i < pAirportManager->airportCount; i++) 
        freeAirport(pAirportManager->airportArr[i]);
    free(pAirportManager->airportArr);
    free(pAirportManager);
}