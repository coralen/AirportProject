#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"

#define MIN_DAY 1
#define MIN_MONTH 1
#define MIN_YEAR 2022
#define DATE_MAX_STRING 100

void initDate(Date* pDate)
{
	int day, month, year;

	getDate(pDate, &day, &month, &year);
	pDate->day = day;
	pDate->month = month;
	pDate->year = year;
}


void getDate(const Date* pDate, int* day, int* month, int* year)
{
	char date[DATE_MAX_STRING];
	int count, validInputFlag = 0;

	printf("Plase enter a date in the format dd##mm##yyyy: ");

	while (!validInputFlag)
	{
		scanf("%s", &date);
		count = sscanf(date, "%2d##%2d##%4d", day, month, year);
		
		if (count != 3 || !validateDate(*day, *month, *year)) {
			printf("Invalid format. Plase enter a date in the format dd##mm##yyyy: ");
			validInputFlag = 0;
		} else validInputFlag = 1;
	}
}


void printDate(const Date pDate)
{
	printf("Date is %d-%d-%d\n", pDate.day, pDate.month, pDate.year);
}


int validateDate(const int day, const int month, const int year)
{
	int max_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (day < MIN_DAY || day > max_days[month - 1]) return 0;
	if (month < MIN_MONTH || month > 12 || year < MIN_YEAR) return 0;

	return 1;
}