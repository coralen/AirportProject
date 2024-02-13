#include <stdio.h>
#include <stdlib.h>

#include "../include/plane.h"


void initPlane(Plane* pPlane)
{
    do {
        printf("Enter plane serial number - between 1 to 9999\n");
        scanf("%d", &(pPlane->serielNumber));
    }while (pPlane->serielNumber<MIN_SERIEL_NUMBER || pPlane->serielNumber>MAX_SERIEL_NUMBER);

    int planeTypeNum;

    do {
        printf("Please enter one of the following types\n"
               "0 for COMMERCIAL\n"
               "1 for Cargo\n"
               "2 for Military\n");

        scanf("%d", &planeTypeNum);

    } while ((planeTypeNum)>PLANE_TYPE_MAX || (planeTypeNum)<PLANE_TYPE_MIN);

    if (planeTypeNum==COMMERCIAL){
        pPlane->planeType  ="COMMERCIAL";
    } else if (planeTypeNum==CARGO){
        pPlane->planeType="CARGO";
    } else if (planeTypeNum==MILIARY) {
        pPlane->planeType = "MILIARY";
    }


}
void printPlane(Plane* pPlane)
{
    printf("Plane: serial number:%d, type %s", pPlane->serielNumber, pPlane->planeType);
}

void freePlane(Plane* pPlane){
    free(pPlane->planeType);
}
