/****
archivo: camino2_01.c
autor: Orome 16/11/2014 14:48:50archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.
segundo tramo dentro de eriador, al sur de los pantanos de moscagua.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino2_base");

create(){
    ::create();

    AddExit("noroeste","./camino1_50");
    AddExit("este","./camino2_02");

    }
