#ifndef _PLANE_H
#define _PLANE_H

typedef enum { COMMERCIAL, CARGO, MILITARY } PlaneType;

typedef struct {
    PlaneType* type;
    int serielNumber;
} Plane;

int initPlane(Plane* pPlane, const Plane* planeArr, const int planeCount);
int isPlaneExist(Plane* pPlane, const Plane* planeArr, const int planeCount);
void printPlane(const Plane* pPlane);
char* stringPlaneType(const PlaneType* type);
void getPlaneType(Plane* pPlane);
void freePlane(Plane* pPlane);

#endif
