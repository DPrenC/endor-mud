/****
archivo: camino1_13.c
autor: Ulmo 22/11/2014 12:32:04
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("norte","./camino1_12");
    AddExit("sureste","./camino1_14");

    }
