/****
archivo: camino1_49.c
autor: Ulmo 20/12/2014 16:37:07
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_48");
    AddExit("sureste","./camino1_50");

    }
