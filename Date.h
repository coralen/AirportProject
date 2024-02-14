#ifndef _DATE_H
#define _DATE_H

typedef struct {
	int day;
	int month;
	int year;
} Date;

void initDate(Date* pDate);
void getDate(int* day, int* month, int* year);
void printDate(const Date pDate);
int validateDate(const int day, const int month, const int year);


#endif
