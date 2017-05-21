/*
DESCRIPCION  : Parada de la diligencia en Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle01.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
               04-11-99 [woo] Como no habia diligencia, he cambiado la
                        descripcion...
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("un porche");
  SetIntLong(
    "Te encuentras en el porche de una caseta de madera que hacía de "
    "oficina de venta de billetes para la diligencia Zarkam-Azzor hace "
    "bastante tiempo. El voladizo del porche protege de la lluvia, "
    "pero no del fresco aire de esta parte alta del valle. En el porche hay "
    "varios viejos bancos de madera.\n");

  AddDetail(({"porche","caseta"}),QueryIntLong());

  AddDetail(({"voladizo"}),
  "El voladizo es la parte del tejado que sobresale de la casa. El de esta caseta "
    "tendra un par de metros de vuelo y esta apoyado sobre gruesos pilares de madera. "
    "Permite evitar la lluvia a los pasajero que esperan aqui la llegada de la "
    "diligencia.\n");

  AddDetail(({"pilares"}),
  "Varios gruesos y resistentes pilares de madera sirven de apoyo para el voladizo "
    "del tejado de la caseta.\n");

  AddDetail(({"bancos","bancos de madera"}),
  "En el porche de esta caseta hay varios viejos bancos de madera desgastados por "
    "estar a la intemperie. En ellos se sientan los pasajeros que pacientemente "
    "esperan el paso de la diligencia.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado en el suroeste "
    "del valle de Azzor, en su parte alta. Sus habitantes se dedican basicamente a "
    "la agricultura y a la destilacion de bebida. La cerveza y el vino de esta zona "
    "son bien conocidos en la region.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
  "Es un importante camino que comunica el valle de Zarkam con los territorios del "
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Este es un lugar tranquilo. No se oye gran cosa.\n");
 SetIntSmell("Un agradable olor a comida llega desde la fonda.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("norte",NARAD("calle01"));
}
