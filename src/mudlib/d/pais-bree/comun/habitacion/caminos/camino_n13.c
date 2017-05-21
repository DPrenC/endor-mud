/*
Fichero: camino_n13.c
Autor: aulë
Fecha: 15/10/2012
Descripción: camino al norte de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();
    
    AddExit("suroeste", "./camino_n12");
    AddExit("norte", "./camino_n14");
    }