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
"intentas te es imposible avanzar a traves del bosque sin hacer ningun ruido. "
"Al este ves la orilla del río Zarmaii y un pequenyo puente que lo cruza.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("este",Z_BOSQUE("bosque_44"));
  AddExit("oeste",Z_BOSQUE("bosque_42"));
  AddExit("noroeste",Z_BOSQUE("bosque_52"));
  AddExit("suroeste",Z_BOSQUE("bosque_32"));
  AddDetail(({"arbol","arboles"}),
  "Los enormes arboles te rodean, impidiendote ver el cielo y ocultandote de posibles "
  "depredadores, el problema es que tambien a ellos les sirven de escondite.\n");
  AddDetail(({"guijarros","ramas"}),
  "El suelo esta repleto de guijarros, ramas y hojas, que producen lo que parece un "
  "estruendoso ruido en el silencio del bosque, solo alterado por el aullido de alguna "
  "bestia.\n");
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Al este ves el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"puente"}),"Al este un pequenyo puente cruza el río Zarmaii.\n");
  SetIntNoise("Oyes crujir las ramas bajo tus pies.\n");
  SetIntSmell("Ueles a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
}
