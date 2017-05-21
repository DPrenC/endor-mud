/****
archivo: camino3_22.c
autor: Ulmo 23/11/2014 17:14:14
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_21");
    AddExit("noreste","./camino3_23");

    }
