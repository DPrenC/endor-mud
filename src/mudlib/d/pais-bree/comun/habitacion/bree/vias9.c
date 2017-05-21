/*
Fichero: vias9.c
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

    AddExit("suroeste", "./vias8");
     AddExit("norte", "./vias10");
     AddExit("este", "./callejon1");
          AddExit("oeste", HABITACION+"bree/comercios/herreria");
              AddDoor("oeste", "la puerta de la herrería",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la herreria", "herrería", "herreria", "puerta del oeste", "oeste", "puerta"}));

 
    }