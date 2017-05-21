/****
archivo: camino3_01.c
autor: Orome 16/11/2014 14:48:50archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
        AddExit("oeste","./camino2_50");
    AddExit("noreste","./camino3_02");

    }
