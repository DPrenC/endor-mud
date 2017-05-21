/*
Fichero: camino_o24.c
Autor: aulë
Fecha: 07/03/2013
Descripción: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("este", "./camino_o23");
    AddExit("suroeste", "./camino_o25");
    }