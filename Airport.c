#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Airport.h"

void initAirportNoCode(Airport* pAirport)
{
	getAirportName(pAirport);
	getAirportCountry(pAirport);
}

void getAirportCode(char* code)
{
	printf("Enter airport code  - 3 UPPER CASE letters	");
	do {
		scanf("%3s", code);
	} while (!isCodeValid(code));
}

void getAirportName(Airport* pAirport)
{
	char name[MAX_STRING];
	
	pAirport->name = NULL;
	printf("Enter airport name\n");
	scanf("%s", name);

	pAirport->name = (char*)realloc(pAirport->name, (strlen(name) + 1) * sizeof(char));
	if (!pAirport->name) return; // Allocation did not work
	strcpy(pAirport->name, name);
}

void getAirportCountry(Airport* pAirport)
{
	char country[MAX_STRING];

	pAirport->country = NULL;
	printf("Enter airport country	");
	scanf("%s", country);
	
	pAirport->country = (char*)realloc(pAirport->name, (strlen(country) + 1) * sizeof(char));
	if (!pAirport->country) return 0; // Allocation did not work

	strcpy(pAirport->country, country);
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


int isSameAirport(Airport* airportPtr1, Airport* airportPtr2)
{
	if (!strcmp(airportPtr1->code, airportPtr2->code)) return 1;
	return 0;
}

int isAirportCode(Airport* airportPtr, const char* code)
{
	if (!strcmp(airportPtr->code, code)) return 1;
	return 0;
}

void printAirport(Airport* pAirport)
{
	printf("Airport name:");
	printWithUnderscores((const char*)pAirport->name);

	printf("A                  Country: %s", pAirport->country);

	printf("                 Code:%c%c%c", pAirport->code[0], pAirport->code[1], pAirport->code[2]);
}

void printWithUnderscores(const char* input)
{
	while (*input != '\0') {
		printf("%c_", *input);
		input++;
	}
	printf("\n");
}

void freeAirport(Airport* pAirport)
{
	free(pAirport->name);
	free(pAirport->country);
}
