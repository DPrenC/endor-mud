/****
archivo: camino1_09.c
autor: Ulmo 16/11/2014 14:44:04
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("noroeste","./camino1_08");
    AddExit("sur","./camino1_10");

    }
