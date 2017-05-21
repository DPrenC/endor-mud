/*
Fichero: camino_n8.c
Autor: aulë
Fecha: 15/10/2012
Descripción: camino al norte de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();
    
    AddExit("sur", "./camino_n7");
    AddExit("noroeste", "./camino_n9");
    }