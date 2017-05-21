/****
archivo: camino1_21.c
autor: Ulmo 23/11/2014 17:12:40
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("norte","./camino1_20");
    AddExit("sur","./camino1_22");

    }
