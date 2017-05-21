/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino interior");
  SetIntLong(
    "Te encuentras en el camino que cruza el bosque hacia la serreria que en el se "
    "encuentra. Al oeste de aqui se abre un claro en este denso bosque y tras el "
    "observas una extranya construccion sobre un gran arbol. El camino avanza desde "
    "el sur hacia el nordeste.\n");

  AddDetail(({"arbol","arboles","cabanya","construccion"}),
     "De entre todos los arboles, el que mas te llama la atencion es uno que se "
     "encuentra situado al noroeste de tu posicion y en el que, al parecer, hay una "
     "construccion de madera en su copa.\n");

  AddDetail(({"claro"}),"Se encuentra al oeste de aqui.\n");

  SetIntNoise("Oyes el cantico de los pajaros.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("suroeste",Z_BOSQUE("bosque_30"));
  AddExit("este",Z_BOSQUE("bosque_42"));
  AddExit("nordeste",Z_BOSQUE("bosque_52"));
  AddExit("sur",Z_BOSQUE("bosque_31"));
}
