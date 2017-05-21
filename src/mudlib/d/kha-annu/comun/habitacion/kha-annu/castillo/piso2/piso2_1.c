/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"

inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("el segundo piso");
  SetIntLong(
"Estas en el segundo piso del castillo de Kha-annu. Todos los detalles de este "
"lugar son muy lujosos... el suelo esta hecho de marmol extraordinariamente "
"trabajado y las paredes de enormes piedras talladas y retocadas con finas "
"lineas de oro. Del techo cuelgan unas hermosas lamparas de diamantes que se "
"extienden a lo largo de todo el corredor.\n");
  SetIntBright(70);

  AddExit("norte",PISO2+"piso2_2");
  AddExit("abajo",PISO1+"stair1");

  AddDetail(({"lampara","lamparas","lampara de diamantes",
              "lamparas de diamantes",}),
"Las lamparas del techo estan hechas con diamantes engarzados entre si. De "
"ellas fluyen luces de todos los colores en toda la estancia.\n");
  AddDetail( ({"suelo"}),
"Ves tu propio reflejo en el suelo junto con el juego de luces de las "
"lamparas del techo.\n");
  AddDetail(({"paredes","pared",}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");
  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
}