/*
Fichero: camino_s21.c
Autor: aul�
Fecha: 08/03/2013
Descripci�n: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("noroeste", "./camino_s20");
    AddExit("sur", "./camino_s22");
    }