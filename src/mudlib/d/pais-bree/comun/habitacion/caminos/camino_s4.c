/*
Fichero: camino_s4.c
Autor: aul�
Fecha: 08/03/2013
Descripci�n: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("norte", "./camino_s3");
    AddExit("suroeste", "./camino_s5");
    }