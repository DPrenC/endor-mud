/*
DESCRIPCION  : Camino que conduce a Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino02.c
MODIFICACION : 11-01-97 [Angor@Simauria] Creacion.
               30-08-98 [Angor@Simauria] Anyadido PNJ
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia Stohenge.");
  SetIntLong(
"Hacia el este, se abre un claro en el bosque por que transcurre el "
"camino que conduce a Stonehenge. En el medio de este claro se encuentra "
"situada una fuente y un poste con varios letreros indicadores. Un camino "
"de tierra cruza de norte a sur este claro del bosque, atravesando el camino "
"principal. El clima es agradable y primaveral.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

  AddDetail(({"fuente","letreros","indicadores","poste"}),
  "Se encuentra en medio del claro, tal vez deberias acercarte mas para ver "
  "con mas detalle.\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("oeste",LIMBO("camino00"));
 AddExit("este",LIMBO("camino03"));
 AddExit("nordeste",LIMBO("camino07"));
 AddExit("sudeste",LIMBO("camino08"));
 AddItem(PNJ("conejo"), REFRESH_DESTRUCT, 1);
}

