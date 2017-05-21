/*
DESCRIPCION  : Zona frondosa en el bosque de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/


#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
"El bosque es realmente denso, te encuentras rodeado de arboles que te "
"impiden el paso en muchas direcciones. Solo en algunos lugares por la "
"poca proximidad de unos arboles con otros o por las caprichosas formas "
"que estos adoptan serias capaz de pasar. "
"Parece que el bosque empieza a abrirse hacia el norte para formar un claro.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("norte",Z_BOSQUE("bosque_48"));
  AddExit("este",Z_BOSQUE("bosque_39"));
  AddExit("oeste",Z_BOSQUE("bosque_37"));
  AddExit("sur",Z_BOSQUE("bosque_28"));
  AddExit("noroeste",Z_BOSQUE("bosque_47"));
  AddDetail(({"arbol","arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado...\n");
  AddDetail(({"formas","forma"}),
  "Algunos arboles se retuercen sobre si mismo, otros forman extranyos arcos "
  "curvos. No crees que estos arboles sean obra de la madre Naturaleza, pero "
  "al menos puedes pasar entre ellos.\n");
  AddDetail(({"claro"}),
  "Mirando hacia el norte, compruebas que disminuye el numero de arboles, hasta "
  "formar un claro en este espeso bosque.\n");
  SetIntNoise("Oyes el cantico de los pajaros.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
  AddItem(QUEST+"amuleto/urraca", REFRESH_DESTRUCT);
}
