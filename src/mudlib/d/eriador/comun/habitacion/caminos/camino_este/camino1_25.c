/****
archivo: camino1_25.c
autor: Ulmo 23/11/2014 17:18:34
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_24");
    AddExit("este","./camino1_26");

    }
