/****
archivo: camino1_48.c
autor: Ulmo 20/12/2014 16:35:50
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_47");
    AddExit("este","./camino1_49");

    }
