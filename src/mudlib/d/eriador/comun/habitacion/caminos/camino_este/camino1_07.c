/****
archivo: camino1_07.c
autor: Ulmo 16/11/2014 14:45:40
archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.
pri
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    SetIntShort("el camino del este");
    AddExit("oeste","./camino1_06");
    AddExit("este","./camino1_08");

    }
