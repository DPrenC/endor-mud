/*
Fichero: camino_o6.c
Autor: aulë
Fecha: 07/03/2013
Descripción: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("sureste", "./camino_o5");
    AddExit("oeste", "./camino_o7");
    }