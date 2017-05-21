/****
archivo: camino3_27.c
autor: Ulmo 23/11/2014 17:20:55
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_26");
    AddExit("noreste","./camino3_28");

    }
