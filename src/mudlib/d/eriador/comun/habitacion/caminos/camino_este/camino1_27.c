/****
archivo: camino1_27.c
autor: Ulmo 23/11/2014 17:20:55
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_26");
    AddExit("este","./camino1_28");

    }
