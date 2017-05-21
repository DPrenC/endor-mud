/*
Fichero: camino_n20.c
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
    
    AddExit("sureste", "./camino_n19");
    AddExit("noreste", "./camino_n21");
    }