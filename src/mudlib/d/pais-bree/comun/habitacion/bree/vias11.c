/*
Fichero: vias11.c
Autor: aul�
Fecha: 13/03/2013
Descripci�n: camino que sube desde la puerta sur de Bree hasta la posada del 
Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/bvias";
create()
{
    ::create();

    AddExit("sur", "./vias10");
     AddExit("norte", "./vias12"); 
    }