/*
Fichero: camino_n21.c
Autor: aulë
Fecha: 08/03/2013
Descripción: camino al norte de la encrucijada hacia Fornost"
 "y las Quebradas del Norte.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();
    
    AddExit("suroeste", "./camino_n20");
    AddExit("este", "./camino_n22");
    }