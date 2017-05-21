/*
DESCRIPCION  : Caverna junto a la entrada de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/caverna6.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("una caverna junto a la entrada de las minas");
  SetIntLong(
  "Te encuentras frente a la entrada de una de las casetas de madera que "
    "hayan construidas junto a las paredes de esta ancha caverna. Al este "
	"de aqui esta la entrada a una de las galerias que se adentran en las "
	"profundidades de las montanyas en busca de vetas de mineral.\n");

  AddDetail(({"casetas","caseta","casetas de madera"}),
  "Son unas construcciones toscas de madera situadas junto a algunas de las "
    "paredes de la caverna. Seguramente seran usadas por los mineros.\n");

  AddDetail(({"galerias"}),
  "Varias galerias parten de esta caverna. No sabes a donde conducen.\n");

  AddDetail(({"railes"}),
  "Son largas vigas de hierro sobre las que se desplazan las vagonetas con "
    "las que se extrae el mineral de las minas.\n");

  SetIntNoise("Se oye el aullar del viento en el exterior de la mina.\n");
  SetIntSmell("Huele a polvo y tierra.\n");
  SetLocate("minas de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("este",Z_MINAS("/nivel0/caverna7"));
  AddExit("norte",Z_MINAS("/nivel0/caverna3"));
  AddExit("oeste",Z_MINAS("/nivel0/almacen0"));
}
