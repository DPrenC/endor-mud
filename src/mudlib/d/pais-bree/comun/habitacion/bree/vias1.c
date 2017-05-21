/*
Fichero: vias1.c
Autor: aulë
Fecha: 12/03/2013
Descripción: camino que sube desde la puerta sur de Bree hasta la posada del 
Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/bvias";
create()
{
    ::create();

    AddExit("sur", "./traspuertas");
     AddExit("norte", "./vias2");
          AddExit("sureste", "./desvio8");
     HideExit("sureste", 1); 
 
    }