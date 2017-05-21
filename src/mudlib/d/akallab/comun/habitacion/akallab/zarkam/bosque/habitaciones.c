/*
DESCRIPCION  : Habitacion (Aserradero en el bosque)
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/habitaciones.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
			   26-10-99 [Angor@Simauria] modificacion/quest
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("la habitación de los leñadores");
  SetIntLong(
  "Estas es una pequenya habitacion cuadrada con dos grandes literas y un "
  "par de mesas. Probablemente es aqui donde los orcos encargados de "
  "trabajar en el aserradero descansen tras una larga y agotadora jornada "
  "de trabajo. La decoracion de la habitacion deja mucho que desear y las "
  "paredes carecen de adorno alguno. Hay una ventana al exterior pero por "
  "su aspecto dirias que esta atascada.\n");

  AddDetail(({"ventana"}), "Es una vieja ventana de madera. Esta atascada.\n");

  AddDetail(({"camas","literas","cama","litera"}),
  "En la habitacion hay dos grandes literas, problablemente, las de los "
  "orcos que cuidan de la presa. No parecen muy comodas.\n");

  AddDetail(({"mesa","mesas"}),
  "Ves unas cuantas mesas repartidas por la estancia. No sabes cual "
  "puede ser su proposito ya que estan desprovistas de cualquier objeto "
  "sobre ellas.\n");

  SetIntNoise("Oyes un fuerte ruido de agua proviniente del oeste.\n");
  SetIntSmell("El olor no es muy agradable.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("oeste",Z_BOSQUE("presa"));

  AddItem(PNJ("z_valle/aken"),REFRESH_DESTRUCT);
  AddItem(QUEST+"amuleto/serrucho", REFRESH_DESTRUCT);
}
