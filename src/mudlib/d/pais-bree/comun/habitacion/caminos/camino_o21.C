/*
Fichero: camino_o21.c
Autor: aulë
Fecha: 07/03/2013
Descripción: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("noreste", "./camino_o20");
    AddExit("oeste", "./camino_o22");
    }