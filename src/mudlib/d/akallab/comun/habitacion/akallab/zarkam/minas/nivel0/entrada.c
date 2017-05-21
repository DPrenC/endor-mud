/*
DESCRIPCION  : Entrada a la mina
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/entrada.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
               12-11-01 [Nemesis@Simauria] Cambiada la l�gica de la funci�n.
               Angor hab�a hecho lo contrario de lo que quer�a: los pnjs pod�an
               salir, pero lo pjs no.
*/

#include "path.h"
#include <moving.h>
#include AK_MACRO
inherit ROOM;

int ir_fuera()
{
  if ((TP->QueryIsPlayer()))
     return TP->move(Z_CAMINO("c_mina06"),M_SPECIAL,
	 ({"se va hacia el este","llega desde el este"}));
  return 1; //los PNJ no salen de la mina
}

create() {
  ::create();
  SetIntShort("el t�nel de entrada a las minas");
  SetIntLong(
  "Estas en un ancho tunel que constituye la entrada a las minas de Zarkam. "
    "De este lugar los orcos extraen metales, principalmente hierro con el "
	"fabricar el acero de sus armas, aunque tambien se han encontrado vetas "
	"de metales preciosos. El suelo del tunel esta recorrido por unos "
	"gastados railes para las vagonetas con las que es extrae el mineral "
    "Hacia el este sales de las minas, y hacia el oeste llegas a lo que "
	"parece ser un caverna.\n");

  AddDetail(({"railes"}),
  "Son dos largas vigas de hierro sobre las que se desplazan las vagonetas.\n");

  SetIntNoise("Se oye el aullar del viento en el exterior de la mina.\n");
  SetIntSmell("Huele a polvo y tierra.\n");
  SetLocate("minas de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("oeste",Z_MINAS("/nivel0/caverna5"));
  AddExit("este",SF(ir_fuera));
}
