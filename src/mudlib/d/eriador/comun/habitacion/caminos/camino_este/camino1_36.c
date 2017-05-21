/****
archivo: camino1_36.c
autor: Ulmo 29/11/2014 12:27:38
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_35");
    AddExit("sureste","./camino1_37");

    }
