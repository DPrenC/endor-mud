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
  SetIntShort("el inicio del camino");
  SetIntLong(
     "Te encuentras en un claro junto al inicio del bosque. Observas que la mayor "
     "parte de este claro se ha formado debido a la tala de los arboles que crecian "
     "en la zona. De los arboles que observas, la mayoria presentan extranyas marcas "
     "rojas realizadas con alguna especie de tinte. Al oeste de aqui un camino se "
     "adentra en el denso e inquietante bosque.\n");

  AddDetail(({"arbol","arboles"}),
     "Algunos de los arboles que todavia quedan en pie presentan unas marcas rojas "
     "como simbolo de que seran talados proximamente.\n");

  AddDetail(({"marca","marcas","rojas"}),
     "Algunos arboles tienen estas marcas para senyalar que tienen que ser talados.\n");

  AddDetail(({"bosque"}), "Hacia el oeste el bosque se hace mas y mas denso.\n");

  SetIntSmell("El aire es humedo.\n");
  SetIntNoise("Oyes un ruido mecanico proveniente del norte.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_BOSQUE("bosque_54"));
  AddExit("norte",Z_BOSQUE("bosque_60"));
  AddExit("oeste",Z_BOSQUE("bosque_52"));
}
