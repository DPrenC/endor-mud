/*
Fichero: camino_s17.c
Autor: aul�
Fecha: 08/03/2013
Descripci�n: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("noreste", "./camino_s16");
    AddExit("suroeste", "./camino_s18");
    }