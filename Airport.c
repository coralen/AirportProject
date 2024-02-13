#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Airport.h"
#include "Helper.h"

void initAirport(Airport* pAirport)
{
	char name[MAX_STRING], country[MAX_STRING];

	// Scan airport code
	printf("Enter airport code  - 3 UPPER CASE letters");
	do {
		scanf("%3s", &pAirport->code);
	} while (!isCodeValid(&pAirport->code));

	// Scan airport name
	printf("Enter airport name\n");
	scanf("%s", &name);
	pAirport->name = realloc(pAirport->name, strlen(name) + 1);
	if (!pAirport->name) return 0; // Allocation did not work
	strcpy(pAirport->name, name);

	// Scan airport country
	printf("Enter airport country");
	scanf("%s", &country);
	pAirport->country = realloc(pAirport->country, strlen(country) + 1);
	if (!pAirport->country) return 0;
	strcpy(pAirport->country, country);
}


void printAirport(const Airport* pAirport)
{
	printf("Airport name:");
	printWithUnderscores((const char*)pAirport->name);
	printf("A                  Country: %s", pAirport->country);
	printf("                 Code:%c%c%c", pAirport->code[0], pAirport->code[1], pAirport->code[2]);
	printf("\n");
}


void printWithUnderscores(const char* input)
{
	while (*input != '\0') 
	{
		printf("%c_", *input);
		input++;
	}
	printf("\n");
}


int isSameAirport(const Airport* pAirport1, const Airport* pAirport2)
{
	for (int i = 0; i < IATA; i++) 
		if (pAirport1->code[i] == pAirport2->code[i]) return 0;
	return 1;
}


int isAirportCode(const Airport* pAirport, const char* code)
{
	for (int i = 0; i < IATA; i++) 
		if (pAirport->code[i] != code[i]) return 0;
	return 1;
}

int isCodeValid(const char* code)
{
	if (strlen(code) != IATA) {
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