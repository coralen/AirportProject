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
	char inCode[MAX_STRING];
	do {
		printf("Enter airport code  - 3 UPPER CASE letters  ");
		scanf(" %[^\n]", &inCode);
	} while (!isCodeValid(inCode));

	printf("\n");
	strcpy(code, inCode);
}

void getAirportName(Airport* pAirport)
{
	char name[MAX_STRING];

	printf("Enter airport name\n");
	scanf(" %[^\n]", name);

	if (!(pAirport->name = (char*)malloc((strlen(name) + 1) * sizeof(char)))) return; 
	strcpy(pAirport->name, name);
}

void getAirportCountry(Airport* pAirport)
{
	char country[MAX_STRING];

	pAirport->country = NULL;
	printf("Enter airport country	");
	scanf("%s", country);

	if (!(pAirport->country = (char*)malloc((strlen(country) + 1) * sizeof(char)))) return;

	printf("\n");
	strcpy(pAirport->country, country);
}

int isCodeValid(const char* code)
{
	if (strlen(code) != IATA)
	{
		printf("code should be 3 letters\n");
		return 0;
	}

	for (int i = 0; i < IATA; i++)
	{
		if (!isupper(code[i]))
		{
			printf("Need to be upper case letter\n");
			return 0;
		}
	}
	return 1;
}


int isSameAirport(const Airport* airportPtr1, const Airport* airportPtr2)
{
	if (!strcmp(airportPtr1->code, airportPtr2->code)) return 1;
	return 0;
}

int isAirportCode(const Airport* airportPtr, const char* code)
{
	if (!strcmp(airportPtr->code, code)) return 1;
	return 0;
}

void printAirport(const Airport* pAirport)
{
	printf("Airport name:");
	printWithUnderscores((const char*)pAirport->name);

	printf("                 Country: %s", pAirport->country);
	printf("                 Code:%s", pAirport->code);
	printf("\n");
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
	free(pAirport);
}