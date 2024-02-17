
CC = gcc
OBJS = main.o Airline.o Airport.o AirportManager.o Helper.o Flight.o Plane.o Date.o
EXEC = prog
DEBUG = -g
CFLAGS = -Wall -Werror $(DEBUG)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

main.o: main.c Airline.h Airport.h AirportManager.h Helper.h Flight.h Plane.h Date.h
Airline.o: Airline.c Airline.h
Airport.o: Airport.c Airport.h Helper.h
AirportManager.o: AirportManager.c AirportManager.h Helper.h Airport.h
Flight.o: Flight.c Flight.h Helper.h
Plane.o: Plane.c Plane.h
Date.o: Date.c Date.h

clean:
	rm -f $(OBJS) $(EXEC)
