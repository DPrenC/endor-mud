/*
Fichero: camino_o16.c
Autor: aul�
Fecha: 07/03/2013
Descripci�n: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("noreste", "./camino_o15");
    AddExit("oeste", "./camino_o17");
    }