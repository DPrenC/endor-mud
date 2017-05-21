/*
Fichero: camino_s5.c
Autor: aulë
Fecha: 08/03/2013
Descripción: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("noreste", "./camino_s4");
    AddExit("suroeste", "./camino_s6");
    }