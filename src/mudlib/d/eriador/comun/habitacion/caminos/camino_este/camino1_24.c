/****
archivo: camino1_24.c
autor: Ulmo 23/11/2014 17:17:14
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("noroeste","./camino1_23");
    AddExit("este","./camino1_25");

    }
