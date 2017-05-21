/*
Fichero: camino1.c
Autor: aulë
Fecha: 04/08/2014
Descripción: pequeño camino que une la calle principal con el paseo por el norte del Poney.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("norte", "./camino2");
     AddExit("sur", "./viao11"); 
    }