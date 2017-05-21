/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"
inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("un pasillo. Segundo piso del castillo");
  SetIntLong("\
Te encuentras en el segundo piso del castillo Kha-annu. Estas justo en el "
"centro de esta planta. Hacia el sur se encuentra el salon del trono y hacia "
"el este continua el pasillo.\n");
  SetIntBright(70);

  AddExit("sur",PISO2+"piso2_10");
  AddExit("este",PISO2+"piso2_6");
  AddExit("oeste",PISO2+"piso2_4");

  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");
  AddDetail( ({"lampara","lamparas"}),
"Ves lamparas de diamante que cuelgan del techo y que despiden una luz "
"azulada.\n");
  AddDetail(({"paredes","pared",}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");
}