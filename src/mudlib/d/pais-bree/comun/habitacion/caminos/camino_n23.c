/*
Fichero: camino_n23.c
Autor: aul�
Fecha: 08/03/2013
Descripci�n: camino al norte de la encrucijada hacia Fornost"
 "y las Quebradas del Norte.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();
    
    AddExit("oeste", "./camino_n22");
    AddExit("noreste", "./camino_n24");
    }