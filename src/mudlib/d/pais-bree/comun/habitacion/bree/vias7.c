/*
Fichero: vias7.c
Autor: aulë
Fecha: 13/03/2013
Descripción: camino que sube desde la puerta sur de Bree hasta la posada del 
Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/bvias";
create()
{
    ::create();

    AddExit("sur", "./vias6");
     AddExit("norte", "./vias8"); 
    }