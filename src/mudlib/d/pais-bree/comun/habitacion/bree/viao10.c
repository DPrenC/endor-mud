/*
Fichero: viao10.c
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

    AddExit("suroeste", "./viao9");
     AddExit("este", "./viao11"); 
    }