/*
DESCRIPCION  : Caverna junto a la entrada de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/caverna4.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("una caverna junto a la entrada de las minas");
  SetIntLong(
  "Te encuentras en el centro de una ancha caverna cerca de la entrada de "
    "estas minas. Observas que desde esta caverna parten varias galerias que "
	"se adentran en las entranyas de las montanyas, y hacia el este, un tunel "
	"que conduce al exterior. Hay un par de pequenyas casetas de madera junto "
	"a las paredes de la caverna. El suelo esta recorrido por varios pares de "
	"railes para las vagonetas.\n");

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

  AddExit("este",Z_MINAS("/nivel0/caverna5"));
  AddExit("norte",Z_MINAS("/nivel0/caverna1"));
  AddExit("oeste",Z_MINAS("/nivel0/caverna3"));
  AddExit("sur",Z_MINAS("/nivel0/caverna7"));
}
