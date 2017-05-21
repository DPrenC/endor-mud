/****
archivo: camino3_02.c
autor: Ulmo 16/11/2014 14:48:24
archivo del tercer tramo del camino de bree a ciudad de los trasgos.
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
        AddExit("suroeste","./camino3_01");
    AddExit("noreste","./camino3_03");

    }
