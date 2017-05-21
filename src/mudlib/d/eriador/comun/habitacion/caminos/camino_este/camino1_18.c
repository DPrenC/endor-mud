/****
archivo: camino1_18.c
autor: Ulmo 22/11/2014 12:39:22
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("noroeste","./camino1_17");
    AddExit("sureste","./camino1_19");

    }
