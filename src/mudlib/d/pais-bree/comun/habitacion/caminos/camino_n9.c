/*
Fichero: camino_n9.c
Autor: aulë
Fecha: 15/10/2012
Descripción: camino al norte de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();

    AddExit("sureste", "./camino_n8");
    AddExit("norte", "./camino_n10");
    }