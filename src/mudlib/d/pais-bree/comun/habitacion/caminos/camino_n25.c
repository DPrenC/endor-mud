/*
Fichero: camino_n25.c
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
    
    AddExit("sur", "./camino_n24");
    AddExit("norte", "./camino_n26");
    }