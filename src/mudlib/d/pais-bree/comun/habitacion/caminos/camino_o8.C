/*
Fichero: camino_o8.c
Autor: aul�
Fecha: 07/03/2013
Descripci�n: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("noreste", "./camino_o7");
    AddExit("noroeste", "./camino_o9");
    }