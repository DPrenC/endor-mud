/****
archivo: camino3_25.c
autor: Ulmo 23/11/2014 17:18:34
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_24");
    AddExit("noreste","./camino3_26");

    }
