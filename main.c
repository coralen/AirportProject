#include "Airline.h"
#include "Airport.h"
#include "AirportManager.h"
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
#include "Helper.h"

int main()
{
	AirportManager manager;
	initManager(&manager);
	Airline company;
	initAirline(&company);

	int choice;


	do {
		printf("Please choose one of the following options\n");
		printf("0 - Add Airport\n");
		printf("1 - Add Plane\n");
		printf("2 - Add Flight\n");
		printf("3 - Print Airline\n");
		printf("4 - Print all Airports\n");
		printf("5 - Print all flights with plane type\n");
		printf("- 1 - Quit\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			if (!addAirport(&manager))
			{
				printf("Error\n");
				freeManager(&manager);
				freeCompany(&company);
				return 0;
			}
			break;

		case 1:
			if (!addPlane(&company))
			{
				printf("Error\n");
				freeManager(&manager);
				freeCompany(&company);
				return 0;
			}
			break;

		case 2:
			if (!addFlight(&company, &manager))
			{
				printf("Error\n");
				freeManager(&manager);
				freeCompany(&company);
				return 0;
			}
			break;

		case 3:
			printCompany(&company);
			break;

		case 4:
			printAirports(&manager);
			break;

		case 5:
			doPrintFlightsWithPlaneType(&company);
			break;
		}
	} while (choice != -1);

	freeCompany(&company);
	freeManager(&manager);
}
