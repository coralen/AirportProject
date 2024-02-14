#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int isSameAirport(Airport* airportPtr1, Airport* airportPtr2)
{
	for (int i = 0; i < IATA; i++) {
		if (airportPtr1->code[i] == airportPtr2->code[i])
			return 0;
	}return 1;
}

int isAirportCode(Airport* airportPtr, const char* code)
{
	for (int i = 0; i < IATA; i++) {
		if (airportPtr->code[i] != code[i])
			return 0;
	}return 1;
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

/* In progress */
void freeAirport() 
{
	

}