/****
archivo: camino1_11.c
autor: Ulmo 22/11/2014 12:29:06
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("norte","./camino1_10");
    AddExit("sur","./camino1_12");

    }
