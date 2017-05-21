/*
Fichero: viao11.c
Autor: aulë
Fecha: 12/03/2013
Descripción: camino que sube desde la puerta oeste de Bree hasta la posada del 
Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/bviao";
create()
{
    ::create();

    AddExit("oeste", "./viao10");
     AddExit("este", "./viao12");
     AddExit("norte", "./camino1"); 
    }