/*
Fichero: camino_o2.c
Autor: aul�
Fecha: 06/03/2013
Descripci�n: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("este", "./camino_o1");
    AddExit("oeste", "./camino_o3");
    }