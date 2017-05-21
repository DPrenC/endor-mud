/****
archivo: camino1_31.c
autor: Ulmo 29/11/2014 12:15:34
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("norte","./camino1_30");
    AddExit("suroeste","./camino1_32");

    }
