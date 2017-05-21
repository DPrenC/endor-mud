/*
Fichero: viao2.c
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

    AddExit("oeste", "./viao1");
     AddExit("este", "./viao3");
     AddExit("sur", "./c1_jardin"); 
            AddDoor("sur", "una cancela",
     "Es una cancela de tablas de madera verticales terminadas en punta triangular, "
     "soportadas por tres tablones horizontales. Cierra el seto en su parte media y se "
     "sustenta en dos postes cuadrados. \n",
     ({"puerta", "s", "sur", "cancela", "puerta sur", "puerta s"}));
 }