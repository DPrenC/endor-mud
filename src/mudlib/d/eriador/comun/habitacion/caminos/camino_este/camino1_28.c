/****
archivo: camino1_28.c
autor: Ulmo 23/11/2014 17:22:38
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_27");
    AddExit("sureste","./camino1_29");

    }
