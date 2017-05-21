/****
archivo: camino3_21.c
autor: Ulmo 23/11/2014 17:12:40
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua***
*/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_20");
    AddExit("norte","./camino3_22");

    }
