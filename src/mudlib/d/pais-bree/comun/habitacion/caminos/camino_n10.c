/*
Fichero: camino_n10.c
Autor: aul�
Fecha: 15/10/2012
Descripci�n: camino al norte de la encrucijada.
*/
#include "./path.h"
inherit HABITACION+"caminos/camino_n0";
create()
{
    ::create();
    
    AddExit("sur", "./camino_n9");
    AddExit("norte", "./camino_n11");
    }