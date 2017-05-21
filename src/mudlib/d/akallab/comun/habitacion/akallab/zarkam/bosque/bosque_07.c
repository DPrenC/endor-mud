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
  SetIntShort("una zona menos frondosa del bosque");
  SetIntLong(
"Estas en una zona despejada del bosque, aqui no hay tantos arboles, "
"solo los que te separan de la zona mas frondosa. "
"Notas que el color de las plantas en esta zona es mucho mas vivo e "
"incluso parecen mas jugosas, por lo que deduces que debe haber algun "
"riachuelo cerca. "
"Hay dos grandes piedras al oeste.\n");
  SetIndoors(0);
  AddExit("norte",Z_BOSQUE("bosque_15"));
  AddExit("oeste",Z_BOSQUE("bosque_06"));
  AddExit("nordeste",Z_BOSQUE("bosque_16"));
  AddDetail(({"arbol","arboles"}),
  "Puedes ver los arboles que forman el limite del bosque, son realmente "
  "enormes.\n");
  AddDetail(({"plantas","planta"}),
  "La vegetacion de este punto del bosque es mas viva, aunque no sabes si "
  "solo te lo parece a ti al no hallarte rodeado de los tetricos arboles "
  "que forman el bosque.\n");
  AddDetail(({"piedras","piedra"}),
  "Dos grandes piedras entre las que se puede pasar, dan acceso al interior "
  "del bosque, aunque puede que no sea tan relajado como esto.\n");
  SetIntNoise("Sin nunguna duda eso es agua...\n");
  SetIntSmell("Llenas tus pulmones con aire puro.\n");
 AddItem(OTRO("hierb_curativa"), REFRESH_REMOVE);
  SetLocate("bosque de Zarkam");
}
