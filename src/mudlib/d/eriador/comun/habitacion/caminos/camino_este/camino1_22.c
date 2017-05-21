/****
archivo: camino1_22.c
autor: Ulmo 23/11/2014 17:14:14
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("norte","./camino1_21");
    AddExit("sureste","./camino1_23");

    }
