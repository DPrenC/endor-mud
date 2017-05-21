/*
Fichero: camino_s25.c
Autor: aulë
Fecha: 08/03/2013
Descripción: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("norte", "./camino_s24");
    //AddExit("sur", "./camino_s25");
    }