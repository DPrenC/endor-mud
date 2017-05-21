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
  SetIntLong(
"Te encuentras en un pasillo en el segundo piso del castillo Kha-annu. Esta "
"parte del pasillo es algo mas oscura. Hacia el norte hay un portal que "
"conduce al salon del trono y algo hacia el sur puedes ver el balcon que "
"da a los jardines del palacio.\n");
  SetIntBright(100);

  AddExit("sur",PISO2+"piso2_12");
  AddExit("norte",PISO2+"hall");

  AddDetail( ({"paredes","pared"}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");
  AddDetail("portal",
"Es solo un portal que adorna la entrada al pasillo que lleva desde el "
"salon del trono al balcon del castillo.\n");
  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
}