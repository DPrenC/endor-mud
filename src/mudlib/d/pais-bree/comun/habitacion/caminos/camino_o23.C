/*
Fichero: camino_o23.c
Autor: aul�
Fecha: 07/03/2013
Descripci�n: camino al oeste de la encrucijada, hacia la Comarca.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_o0";
create()
{
    ::create();

    AddExit("sureste", "./camino_o22");
    AddExit("oeste", "./camino_o24");
    }