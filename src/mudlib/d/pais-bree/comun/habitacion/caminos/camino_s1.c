/*
Fichero: camino_s1.c
Autor: aul�
Fecha: 08/03/2013
Descripci�n: camino al sur de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_s0";
create()
{
    ::create();

    AddExit("norte", "./encrucijadasur");
    AddExit("sur", "./camino_s2");
    }