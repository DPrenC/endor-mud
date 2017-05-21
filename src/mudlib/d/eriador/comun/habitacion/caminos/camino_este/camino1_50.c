/****
archivo: camino1_50.c
autor: Ulmo 20/12/2014 16:38:39
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino1_base");

create(){
    ::create();
    AddExit("noroeste","./camino1_49");
    AddExit("sureste","./camino2_01");

    }
