/*
Fichero: camino3.c
Autor: aulë
Fecha: 04/08/2014
Descripción: pequeño camino que une la calle principal con el paseo por el norte del Poney.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("norte", "./camino4");
     AddExit("sur", "./camino2"); 
    }