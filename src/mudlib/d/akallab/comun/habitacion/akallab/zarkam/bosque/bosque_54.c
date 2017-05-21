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
  SetPreIntShort("frente a");
  SetIntShort("una cabaña");
  SetIntLong(
     "Estas justo en frente de una cabanya. Es una cabanya un tanto especial, ya que "
     "cruza el río Zarmaii de una orilla a otra a modo de presa. Por el ruido que te "
     "llega desde ella parece ser un aserradero de madera. Seguramente el que provee a "
     "Zarkam de toda su madera. El río queda hacia el este.\n");

  AddDetail(({"montanyas","cordillera","Kova"}),
      "Al norte se encuentra la abrupta cordillera de Kova.\n");

  AddDetail(({"cabanya","presa"}),
      "Puedes ver una cabanya que sirve de aserradero y almacen de madera a los orcos "
      "de Zarkam.\n");

  AddDetail(({"río","afluente","Zarmaii"}),
      "Desde aqui ves como el río Zarmaii es retenido por la presa retornando a su "
      "cauce a traves de varias compuertas.\n");

  SetIntSmell("El aire es humedo.\n");
  SetIntNoise("Oyes ruido de sierras proveniente de la cabanya.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_BOSQUE("bosque_55"));
  AddExit("norte",Z_BOSQUE("cabanya"));
  AddExit("oeste",Z_BOSQUE("bosque_53"));
}
