/*
DESCRIPCION  : Arbol
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/arbol_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("sobre");
  SetIntShort("una plataforma en un árbol");
  SetIntLong(
"Bajo tus pies una plataforma de madera te mantiene a salvo de una peligrosa "
"caida. Tambien son de ayuda las cuatro barandillas de madera que te rodean. "
"Sin lugar a dudas, el lugar en cuestion esta firmemente construido, y cumple "
"a la perfeccion su funcion de puesto de vigia, desde aqui puedes ver todo el "
"bosque, aunque las copas de los arboles que ahi por debajo tuya no dejan que "
"tu vision transpase su manto de ramas. Aun asi si puedes ver a la perfeccion "
"el claro del noroeste, una cabanya al nordeste, un río al este y la entrada "
"al bosque al sudoeste.\n");
  SetIndoors(0);
  AddExit("abajo",Z_BOSQUE("bosque_40"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Al este ves el río Zarmaii, afluente del Kusaii. Puedes contemplarlo desde su "
  "nacimiento al norte, hasta que se pierde de vista por el sur.\n");
  AddDetail(({"cabanya"}),
  "Al nordeste, y sobre el Zarmaii, ves una cabanya bastante grande que cruza el "
  "río de orilla a orilla.\n");
  AddDetail(({"claro"}),
  "No muy lejos de tu posicion, al nordeste, aprecias un claro en el bosque. "
  "Aunque desde aqui, todo se ve muy pequenyo dirias que el claro esta repleto "
  "de cuerpos y esqueletos.\n");
  AddDetail(({"entrada","camino"}),
  "Desde aqui se controla a la perfeccion la entrada que hay al sudeste del "
  "bosque, asi como el camino que se aleja en esa direccion.\n");
  SetIntNoise("El aire silba entre las hojas.\n");
  SetIntSmell("El olor tipico de la copa de un arbol...\n");
  SetLocate("bosque de Zarkam");
}

