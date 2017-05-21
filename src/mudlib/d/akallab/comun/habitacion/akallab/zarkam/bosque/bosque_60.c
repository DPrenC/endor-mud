/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("ante");
  SetIntShort("la cabaña");
  SetIntLong(
  "Estas justo en frente de una cabanya. Es una cabanya un tanto especial, ya "
  "que cruza el río Zarmaii de una orilla a otra a modo de presa. Por el  "
  "ruido que sale de ella parece ser un aserradero de madera. Seguramente el "
  "que provee a Zarkam de toda su madera. La puerta debe quedar al sur. "
  "Puedes entrar a la cabanya por el este o acercarte a las montanyas hacia el "
  "norte.\n");
  AddDetail(({"montanyas","cordillera","Kova"}),
  "Al norte se encuentra la abrupta cordillera de Kova.\n");
  AddDetail(({"cabanya","presa"}),
  "Puedes ver una cabanya que sirve de aserradero y almacen de madera a los orcos "
  "de Zarkam.\n");
  AddDetail(({"río","afluente","Zarmaii"}),
  "Desde aqui ves como el río Zarmaii es retenido por la presa retornando a su "
  "cauce a traves de varias compuertas.\n");
  AddExit("norte",Z_BOSQUE("bosque_64"));
  AddExit("sur",Z_BOSQUE("bosque_53"));
  AddExit("suroeste",Z_BOSQUE("bosque_52"));
  SetIndoors(0);
  SetIntSmell("El aire es humedo.\n");
  SetIntNoise("Oyes ruido de sierras proveniente de la cabanya.\n");
  SetLocate("bosque de Zarkam");
}
