#ifndef _DATE_H
#define _DATE_H

typedef struct {
	int day;
	int month;
	int year;
} Date;

void getCorrectDate(Date* pDate);
void printDate(const Date* pdate);
int validateDate(const int day, const int month, const int year);


#endif
