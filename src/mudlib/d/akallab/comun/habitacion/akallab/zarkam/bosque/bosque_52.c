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
     "El camino continua avanzando a traves del bosque. Observas como hacia el norte "
     "el terreno se va haciendo cada vez mas empinado a medida que se acercan las "
     "montanyas. Observas como se abre un claro hacia al este de aqui. El camino "
     "avanza desde el suroeste hacia el este.\n");

  AddDetail(({"claro"}), "Al este puedes ver un claro.\n");

  SetIntNoise("Oyes el cantico de los pajaros.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("suroeste",Z_BOSQUE("bosque_41"));
  AddExit("este",Z_BOSQUE("bosque_53"));
  AddExit("sudeste",Z_BOSQUE("bosque_43"));
  AddExit("nordeste",Z_BOSQUE("bosque_60"));
}
