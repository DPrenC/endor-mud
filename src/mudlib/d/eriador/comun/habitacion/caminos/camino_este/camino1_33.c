/****
archivo: camino1_33.c
autor: Ulmo 29/11/2014 12:22:54
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("norte","./camino1_32");
    AddExit("sureste","./camino1_34");

    }
