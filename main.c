#include <stdlib.h>
#include <stdio.h>

#include "Airport.h"
#include "Airportmanager.h"
#include "Plane.h"
#include "Date.h"
#include "Flight.h"
#include "Airline.h"
#include "Helper.h"

//caseine
//////////////////

#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airline.h"

int main()
{
	Airline company;
	//This function gets the pointer to the struct airline
	//The function ask the user for airline name and set other
	// arrays to NULL and count to 0
	initAirline(&company);

	for (int i = 0; i < 4; i++)
	{
		//This function get the pointer to the struct airline
		//and adds plane to the array
		if (!addPlane(&company))
			break;
	}
	printf("Airline name %s\n", company.name);
	printPlanesArr(company.planeArr, company.planeCount);
	freeCompany(&company);
}

/// ///////////
int mainTEST()
{
	printf("Press the Enter key to continue\n");
	(void)getc(stdin);

	return 0;
}
