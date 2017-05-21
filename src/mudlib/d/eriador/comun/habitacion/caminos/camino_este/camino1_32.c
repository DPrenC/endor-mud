/****
archivo: camino1_32.c
autor: Ulmo 29/11/2014 12:21:09
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("noreste","./camino1_31");
    AddExit("sur","./camino1_33");

    }
