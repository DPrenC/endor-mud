/*
Fichero: vias9.c
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

    AddExit("suroeste", "./vias8");
     AddExit("norte", "./vias10");
     AddExit("este", "./callejon1");
          AddExit("oeste", HABITACION+"bree/comercios/herreria");
              AddDoor("oeste", "la puerta de la herrer�a",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la herreria", "herrer�a", "herreria", "puerta del oeste", "oeste", "puerta"}));

 
    }