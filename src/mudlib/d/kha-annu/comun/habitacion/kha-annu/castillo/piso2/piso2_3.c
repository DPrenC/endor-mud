/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"

inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("el segundo piso del Castillo");
  SetIntLong(
"Caminas a traves del corredor del segundo piso del castillo. Estas ahora "
"justo en la parte noroeste de esta planta. El corredor continua hacia el "
"este, iluminado por unas bellisimas lamparas.\n");

  SetIntBright(70);

  AddExit("sur",PISO2+"piso2_2");
  AddExit("este",PISO2+"piso2_4");

  AddDetail(({"lampara","lamparas","lampara de diamantes",
              "lamparas de diamantes",}),
"Las lamparas del techo estan hechas con diamantes engarzados entre si. De "
"ellas fluyen luces de todos los colores en toda la estancia.\n");
  AddDetail("suelo","Ves tu propio reflejo en el suelo junto con el juego de "
"            luces que crean las lamparas del techo.\n");
  AddDetail(({"paredes","pared",}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");

  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
}