/****
archivo: camino1_26.c
autor: Ulmo 23/11/2014 17:19:46
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    AddExit("oeste","./camino1_25");
    AddExit("este","./camino1_27");

    }
