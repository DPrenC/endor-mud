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
Caminas por el pasillo del segundo piso del castillo. Si caminas hacia el "
"oeste podras llegar al salon del trono, donde el rey Belthain celebra sus "
"audiencias; y hacia el este continua el corredor.\n");
  SetIntBright(70);

  AddExit("este",PISO2+"piso2_7");
  AddExit("oeste",PISO2+"piso2_5");

  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");
  AddDetail( ({"lampara","lamparas"}),
"Ves lamparas de diamante que cuelgan del techo y que despiden una luz "
"azulada.\n");
  AddDetail(({"paredes","pared",}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");
}