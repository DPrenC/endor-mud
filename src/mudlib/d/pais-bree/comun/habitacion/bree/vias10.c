/*
Fichero: vias10.c
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

    AddExit("sur", "./vias9");
     AddExit("norte", "./vias11"); 
    }