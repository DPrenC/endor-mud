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
  SetIntShort("el bosque junto a la cordillera de Kova");
  SetIntLong(
  "Estas bajo las laderas de la cordillera de Kova. Esta alza sus majestuosas "
  "montanyas al norte de tu posicion. Lo que hace completamente imposible el "
  "avance en esa direccion. "
  "Al este puedes ver una amplia cabanya de madera construida sobre el río "
  "Zarmaii. Desde esta posicion no lo puedes apreciar con mucha claridad, "
  "pero parece una presa y un almacen o un aserradero de madera. "
  "Al suroeste, un estrecho camino discurre entre el bosque y las montanyas.\n");
  AddDetail(({"cordillera","Kova","montana","montanyas"}),
  "A tu lado se encuentra la cordillera de Kova. La pared rocosa de la montanya "
  "que tienes ante ti es extremadamente lisa e imposible de escalar incluso para "
  "los mas diestros.\n");
  AddDetail(({"cabanya","presa","almacen","aserradero"}),
  "Al este ves una cabanya de madera de unas dimensiones considerables.\n");
  AddDetail(({"río","afluente","Zarmaii"}),
  "Puedes ver hacia el este el río Zarmaii, afluente natural del Kusaii.\n");
  AddExit("oeste",Z_BOSQUE("bosque_63"));
  AddExit("sur",Z_BOSQUE("bosque_60"));
  AddExit("suroeste",Z_BOSQUE("bosque_59"));
  AddExit("este",Z_BOSQUE("maquinaria"));

  SetIndoors(0);
  SetIntSmell("El olor es el de la vegetacion del bosque.\n");
  SetIntNoise("Escuchas como caen pequenyas piedrecillas desde la montanya.\n");
  SetLocate("bosque de Zarkam");
}
