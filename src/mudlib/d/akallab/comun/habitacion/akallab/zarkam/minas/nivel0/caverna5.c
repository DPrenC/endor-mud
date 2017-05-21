/*
DESCRIPCION  : Caverna junto a la entrada de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/caverna5.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
MODIFICACION : 07-11-01 [Cheto@Simauria] Modificacion para el quest
		de la copa
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("una caverna junto a la entrada de las minas");
  SetIntLong(
  "Estas en una ancha caverna cerca de la entrada de estas minas. Hacia el "
    "este un ancho tunel conduce al exterior. Observas que desde esta caverna "
	"parten varias galerias que se adentran en las entranyas de las montanyas "
	"en busca de las preciadas vetas de mineral. Los orcos han construido un "
	"par de pequenyas casetas de madera junto a las paredes de la caverna. "
	"ves una pequeña sala al nordeste con un arco demasiado trabajado para"
	"las habilidades de los orcos"
	"El suelo esta recorrido por varios pares de railes para las vagonetas.\n");

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

  AddExit("este",Z_MINAS("/nivel0/entrada"));
  AddExit("norte",Z_MINAS("/nivel0/caverna2"));
  AddExit("oeste",Z_MINAS("/nivel0/caverna4"));
  AddExit("sur",Z_MINAS("/nivel0/caverna8"));
  AddExit("nordeste",Z_MINAS("/nivel0/santuario"));
}
