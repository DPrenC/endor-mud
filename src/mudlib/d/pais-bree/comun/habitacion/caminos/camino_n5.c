/*
Fichero: camino_n5.c
Autor: aul�
Fecha: 15/10/2012
Descripci�n: camino al norte de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();

    AddExit("sureste", "./camino_n4");
    AddExit("norte", "./camino_n6");
    }