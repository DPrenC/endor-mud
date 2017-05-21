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
Estas en la parte mas al noreste de este piso. Hacia el oeste esta el salon "
"del trono y algo hacia el sur ves unas escaleras.\n");
  SetIntBright(70);

  AddExit("sur",PISO2+"piso2_8");
  AddExit("oeste",PISO2+"piso2_6");

  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");
  AddDetail( ({"lampara","lamparas"}),
"Ves lamparas de diamante que cuelgan del techo y que despiden una luz "
"azulada.\n");
  AddDetail(({"paredes","pared",}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");
  AddDetail(({"escalera","escaleras","sur"}),
 "Las escaleras se encuentran algo hacia el sur.\n");

  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
}