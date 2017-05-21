/*
Fichero: antepuertas.c
Autor: aulë
Fecha: 12/03/2013
Descripción: Lugar ante la puerta sur de Bree.
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();

    AddExit("sureste", "./caminodeleste1");
     AddExit("norte", HABITACION+"bree/traspuertas");
          AddDoor("norte", "una robusta puerta de trancas",
     "Es una robusta puerta de unos dos metros de altura constituida por gruesas "
     "trancas de madera reforzadas con herrajes y con la punta aguzada.\n"
     "Varios pesados cerrojos y pestillos la aseguran y posee un par de ventanucos "
     "a la altura de un Hobbit y de un Hombre respectivamente para examinar el "
     "exterior e identificar a quien llame tras la puesta de sol.\n",
     ({"puerta", "trancas", "puerta de trancas", "n", "norte"}));
     
 
    }