/*
Fichero: camino_s11.c
Autor: aul�
Fecha: 08/03/2013
Descripci�n: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("norte", "./camino_s10");
    AddExit("sureste", "./camino_s12");
    }