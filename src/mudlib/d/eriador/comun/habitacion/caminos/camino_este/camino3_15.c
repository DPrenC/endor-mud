/****
archivo: camino3_15.c
autor: Ulmo 22/11/2014 12:35:12
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_14");
    AddExit("noreste","./camino3_16");

    }
