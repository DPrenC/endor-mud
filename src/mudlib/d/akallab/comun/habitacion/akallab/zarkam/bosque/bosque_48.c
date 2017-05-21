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
  SetIntShort("un claro en el bosque");
  SetIntLong(
"Te hayas rodeado de cientos de arboles talados, que crean un paisaje bastante "
"desolador. Alguien se ha dedicado a talar arboles indiscriminadamente, dejando "
"esta zona del bosque totalmente despoblada. En muchos metros a la redonda no "
"hay ningun lugar donde sea posible ocultarse. "
"Pero pese a todo lo que mas te llama la atencion son unas extranyas formas que "
"se alzan hacia el norte, pero que no consigues distinguir claramente desde aqui.\n");
  SetIndoors(0);
  AddExit("este",Z_BOSQUE("bosque_49"));
  AddExit("sur",Z_BOSQUE("bosque_38"));
  AddExit("norte",Z_BOSQUE("bosque_57"));
  AddExit("nordeste",Z_BOSQUE("bosque_58"));
  AddDetail(({"arbol","arboles"}),
  "Los enormes arboles que poblaban esta zona han sido salvajemente talados.\n");
  AddDetail(({"forma","formas"}),
  "Al norte ves unas extranyas formas que, aunque no distingues a la perfeccion, te "
  "parecen cuerpos enpalados.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntSmell("Ueles a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
}
