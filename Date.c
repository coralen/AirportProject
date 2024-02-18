#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Date.h"
#include "Helper.h"

#define MIN_DAY 1
#define MIN_MONTH 1
#define MIN_YEAR 2022
#define SEGMENTS 3

void getCorrectDate(Date* pDate)
{
	char date[MAX_STRING];
	int count, validInputFlag = 0, day = 0, month = 0, year = 0;

	while (!validInputFlag)
	{
		printf("Enter Flight Date dd##mm##yyyy  minimum year 2023\n");
		scanf("%s", date);
		count = sscanf(date, "%2d##%2d##%4d", &day, &month, &year);

		if (count != SEGMENTS || !validateDate(day, month, year)) {
			printf("Error try again\n");
			validInputFlag = 0;
		}
		else validInputFlag = 1;
	}

	pDate->day = day;
	pDate->month = month;
	pDate->year = year;
}


void printDate(const Date* pdate)
{
	printf("%d/%d/%d", pdate->day, pdate->month, pdate->year);
}


int validateDate(const int day, const int month, const int year)
{
	int max_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (day < MIN_DAY || day > max_days[month - 1]) return 0;
	if (month < MIN_MONTH || month > 12 || year <= MIN_YEAR) return 0;

	return 1;
}

void freeDate(Date* pDate)
{
	free(pDate);
}
