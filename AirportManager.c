#include <stdio.h>
#include <stdlib.h>

#include "AirportManager.h"
#include "Helper.h"

int initAirportManager(AirportManager* pAirportManager) 
{
    pAirportManager->airportCount = 0;
    pAirportManager->airportArr = NULL;
}

int addAirport(AirportManager* pAirportManager)
{
    Airport* pAirport = NULL;

    pAirportManager->airportArr = (Airport)realloc(pAirportManager->airportArr, (pAirportManager->airportCount + 1) sizeof(Airport));
    if (!pAirportManager->airportArr) return 0;
    pAirportManager->airportCount++;
    pAirport = pAirportManager->airportArr[pAirportManager->airportCount - 1];

    do {
        getAirportCode(pAirport->code);
        if (findAirportByCode(pAirportManager, pAirport->code)) printf("This code already in use - enter a different code");
    } while (!findAirportByCode(pAirportManager, pAirport->code));

    initAirportNoCode(pAirport, pAirportManager);

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
        printAirport(&(pAirportManager->airportArr[i]));
    }
}

void freeAirportManagar(AirportManager* pAirportManager) 
{
    for (int i = 0; i < pAirportManager->airportCount; i++) {
        freeAirport(pAirportManager->airportArr[i]);
        free(pAirportManager->airportArr+i);
    }
    free(pAirportManager);
}
