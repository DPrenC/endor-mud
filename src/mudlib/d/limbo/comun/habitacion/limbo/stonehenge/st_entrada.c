/*
DESCRIPCION  : Entrada a Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/st_entrada.c
MODIFICACION : 23-01-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("la entrada a Stonehenge.");
  SetIntLong("Te encuentras bajo un arco en el muro exterior de Stonehenge que sirve como "
"entrada a este monumento. Desde aqui observas los dos muros concentricos de "
"piedra que forman su estructura. Estos muros estan formados por inmensos arcos, "
"algunos de los cuales son portales que se comunican, de forma inexplicable, con "
"otros muchos lugares a lo largo y ancho de Simauria.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

 AddDetail(({"portal","portales"}),
 "Algunos de los arcos de piedra de Stonehenge son portales que permiten a un "
  "individuo ser teletransportado a la region de Simauria en la que viven los de "
  "raza.\n");

SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);

AddExit("norte",STONE("portal_draconiano"));
AddExit("este",LIMBO("camino01"));
AddExit("sur",STONE("portal_logath"));
AddExit("suroeste",STONE("portal_4"));
AddExit("oeste",STONE("st_agua"));
AddExit("noroeste",STONE("portal_3"));
}
