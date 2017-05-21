/*
Fichero: camino_s9.c
Autor: aulë
Fecha: 08/03/2013
Descripción: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("noroeste", "./camino_s8");
    AddExit("sur", "./camino_s10");
    }