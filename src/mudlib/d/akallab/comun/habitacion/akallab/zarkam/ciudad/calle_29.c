/*
DESCRIPCION : calle de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_29.c
MODIFICACION: 11-10-98 [Angor@Simauria] Creacion
              24-11-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("una calle de Zarkam");
 SetIntLong(
    "Te encuentras en una calle que conduce desde la plaza central de Zarkam hasta el\n"
    "Barrio de los Artesanos. La plaza queda al oeste de aqui y el barrio un poco mas\n"
    "lejos hacia el este. Al sur de aqui queda la entrada al establo de la posada.\n");

  AddDetail(({"establo","posada"}),
    "La posada es el gran edificio que queda al suroeste. La entrada a su establo se\n"
    "halla justamente al sur de aqui.\n");

  AddDetail(({"barrio","Barrio","barrio de los artesanos","Barrio de los Artesanos"}),
    "No puedes verlo desde aqui. Se halla al nordeste de la ciudad.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_CIUDAD("calle_28"));
  AddExit("oeste",Z_CIUDAD("plaza_03"));
  AddExit("sur",Z_POSADA("establo"));
}
