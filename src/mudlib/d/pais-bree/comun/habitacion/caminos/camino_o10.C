/*
Fichero: camino_o10.c
Autor: aul�
Fecha: 07/03/2013
Descripci�n: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("sureste", "./camino_o9");
    AddExit("noroeste", "./camino_o11");
    }