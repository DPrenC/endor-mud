/*
DESCRIPCION  : Calle principal del pueblo de la isla Limbo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/calle03.c
MODIFICACION : 02-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la calle principal del pueblo de la isla Limbo");
  SetIntLong(
"Te hallas aproximadamente en la mitad de la calle principal del poblado. Al "
"norte de aquí observas como la calle llega a una plaza y hacia el sur, como "
"acaba en el muelle. Al oeste se encuentra el banco, un bajo y recio edificio "
"de piedra, y al este otro edificio, que parece estar cerrado.\n");

AddDetail(({"puerto","muelle","barcas"}),
 "A lo lejos ves el puerto con barcas amarradas en su muelle. Deberias acercarte "
 "si quieres verlo con mas detalle.\n");

AddDetail(({"plaza"}),"Es una pequeña esplanada que queda al norte.\n");
AddDetail(({"banco"}),"Es el edificio bajo que queda al oeste de aquí.\n");
AddDetail(({"este","edificio cerrado"}),
          "Es un edificio casi tan grande como el situado enfrente, al "
          "oeste. En su fachada ves un cartel en el que pone: Oficina de "
          "consignas... ¡Abriremos en breve!\n");
          ;

SetIntNoise("Oyes el murmullo de la actividad en el pueblo.\n");
SetIntSmell("El olor del campo se confunde con el del mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("norte",LIMBO("calle01"));
AddExit("sur",LIMBO("calle02"));
AddExit("oeste",LIMBO("banco"));
}
