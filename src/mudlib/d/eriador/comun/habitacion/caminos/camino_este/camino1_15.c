/****
archivo: camino1_15.c
autor: Ulmo 22/11/2014 12:35:12
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_14");
    AddExit("este","./camino1_16");

    }
