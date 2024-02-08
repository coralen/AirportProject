#ifndef _DATE_H
#define _DATE_H

#include "utilities.h"

typedef struct
{
	int day;
	int month;
	int year;
} Date;

void getAttributes();
void printDate();
int validateDate();

#endif