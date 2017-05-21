/****
archivo: camino3_26.c
autor: Ulmo 23/11/2014 17:19:46
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_25");
    AddExit("norte","./camino3_27");

    }
