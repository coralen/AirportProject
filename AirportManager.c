#include <stdio.h>
#include <stdlib.h>

#include "AirportManager.h"
#include "Helper.h"

int initAirportManager(AirportManager* pAirportManager) 
{
	pAirportManager->airportCount = 0;
}

/* In progress */
int addAirport(AirportManager* pAirportManager)
{
    Airport* pAirport;
    char code[IATA];

    initAirport(pAirport);
    pAirportManager->airportCount++;
    pAirportManager->airports = realloc(pAirportManager->airports, pAirportManager->airportCount * sizeof(Airport));
    if (!pAirportManager->airports) return 0;
    pAirportManager->airports[pAirportManager->airportCount] = pAirport;

    printf("Enter airport code  - 3 UPPER CASE letters");

    do {
        scanf("%3s", &pAirport->code); // I changed code to pAirport->code cause the size is constant
    } while (!isCodeValid(&pAirport->code));

    //for (int i = 0; i < IATA; i++) // No need
    //    pAirport->code[i] = code[i]; // No need

    printf("Enter airport name\n");
    scanf("%s", pAirport->name); // Add memory allocation

    pAirport->name = malloc(strlen(pAirport->name) + 1);
    strcpy(pAirport->name, pAirport->name); // Add memory allocation

    printf("Enter airport country");
    scanf("%s", &pAirport->country); // Add memory allocation
}

int isCodeValid(const char* code)
{
    if (strlen(code) != IATA) 
    {
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

/* In progress */
char* findAirportByCode(AirportManager* pAirportManager, char* code) 
{
    for (int i = 0; i < pAirportManager->airportCount; i++) 
    {
        if (!compareCodes(pAirportManager->airports[i]->code, code, IATA)) return pAirportManager->airports[i];
    }
    return NULL;
}

int compareCodes(char* code1, char* code2, int len)
{
    int countCode;

    for (int i = 0; i < len; i++)
        if (code1[i] != code2[i]) countCode++;
    if (countCode == 3) return 1;
    return 0;
}

void printAirportManager(AirportManager* pAirportManager)
{
    printf("there are %d airports\n", pAirportManager->airportCount);
    for (int i = 0; i < pAirportManager->airportCount; i++) {
        printAirport(&(pAirportManager->airports[i]));
    }
}

void freeAirportManagar(AirportManager* pAirportManager) 
{
    for (int i = 0; i < pAirportManager->airportCount; i++) 
        freeAirport(pAirportManager->airports[i]);
}