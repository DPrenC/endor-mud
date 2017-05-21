/****
archivo: camino1_40.c
autor: Ulmo 29/11/2014 12:34:46
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("noroeste","./camino1_39");
    AddExit("sureste","./camino1_41");

    }
