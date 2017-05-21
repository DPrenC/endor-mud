/****
archivo: camino1_01.c
autor: Orome 16/11/2014 14:48:50archivo del segundo tramo del camino de bree a ciudad de los trasgos.
nombre real del camino: gran camino del este.
primer tramo dentro de Eriador, pero segundo según desde Bree

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR1("camino1_base");

create(){
    ::create();
    SetIntShort("el camino del este");
    AddExit("oeste",CAMINO_ESTE_BREE("caminodeleste50"));
    AddExit("este","./camino1_02");

    }
