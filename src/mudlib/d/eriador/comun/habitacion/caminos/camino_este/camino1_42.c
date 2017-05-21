/****
archivo: camino1_42.c
autor: Ulmo 20/12/2014 16:26:09
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_41");
    AddExit("sur","./camino1_43");

    }
