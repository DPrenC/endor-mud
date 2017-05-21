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
  SetIntShort("el interior del bosque");
  SetIntLong(
"Los grandes arboles te rodean produciendote una sensacion de proteccion asi "
"como algo de temor. En este oscuro bosque, habitan diversos tipos de animales, "
"algunos no muy amigables con los forasteros. "
"Ramas y guijarros crujen bajo tus pies con cada paso que das, por mas que lo "
"intentas te es imposible avanzar a traves del bosque sin hacer ningun ruido, "
"pero no es solo el ruido de tus pisadas lo que te preocupa, tambien lo hacen "
"los extranyos aullidos que oyes de vez en cuando.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("este",Z_BOSQUE("bosque_38"));
  AddExit("norte",Z_BOSQUE("bosque_47"));
  AddDetail(({"arbol","arboles"}),
  "Los enormes arboles te rodean, impidiendote ver el cielo y ocultandote de posibles "
  "depredadores, el problema es que tambien a ellos les sirven de escondite.\n");
  AddDetail(({"guijarros","ramas"}),
  "El suelo esta repleto de guijarros, ramas y hojas, que producen lo que parece un "
  "estruendoso ruido en el silencio del bosque, solo alterado por el aullido de alguna "
  "bestia.\n");
  SetIntNoise("Oyes crujir las ramas bajo tus pies.\n");
  SetIntSmell("Ueles a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
}
