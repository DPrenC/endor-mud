/*
Fichero: camino_s2.c
Autor: aulë
Fecha: 08/03/2013
Descripción: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("norte", "./camino_s1");
    AddExit("sur", "./camino_s3");
    }