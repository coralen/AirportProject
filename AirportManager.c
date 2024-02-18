#include <stdio.h>
#include <stdlib.h>

#include "AirportManager.h"
#include "Helper.h"

 int initManager(AirportManager* pAirportManager)
{
    pAirportManager->airportCount = 0;
    if (!(pAirportManager->airportArr = (Airport**)malloc(sizeof(Airport*)))) return 0;
    return 1;
}

int addAirport(AirportManager* pAirportManager)
{
    if (!(pAirportManager->airportArr = (Airport**)realloc(pAirportManager->airportArr, (pAirportManager->airportCount + 1) * sizeof(Airport*)))) return 0;
    if (!(pAirportManager->airportArr[pAirportManager->airportCount] = (Airport*)malloc(sizeof(Airport)))) return 0;

    do {
        getAirportCode(pAirportManager->airportArr[pAirportManager->airportCount]->code);
        if (findAirportByCode(pAirportManager, pAirportManager->airportArr[pAirportManager->airportCount]->code)) 
            printf("This code already in use - enter a different code\n");
    } while (findAirportByCode(pAirportManager, pAirportManager->airportArr[pAirportManager->airportCount]->code));

    initAirportNoCode(pAirportManager->airportArr[pAirportManager->airportCount]);
    pAirportManager->airportCount++;

    return 1;
}

// coral: we must use "isAirportCode"(in the pdf questions) instead of "isSameCode"
Airport* findAirportByCode(const AirportManager* pAirportManager, const char* code) 
{
    for (int i = 0; i < pAirportManager->airportCount; i++) 
        if (isAirportCode(pAirportManager->airportArr[i], code)) return pAirportManager->airportArr[i];
    return NULL;
}

//int isSameCode(const char* code1, const char* code2)
//{
//    int countCode = 0;

//    for (int i = 0; i < IATA; i++)
//        if (code1[i] != code2[i]) countCode++;
//    if (countCode == 3) return 1;
//    return 0;
//}

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