/* Created by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria, para implementar a Nightfall(tm).
   Ultima modificacion: 10 Oct, 1997.
 */

#include "path.h"
inherit KHA_ROOM;

create()
{
  ::create();
  SetIntShort("la lavandería");
  SetIntLong(
"Has llegado a la lavanderia del castillo. La ropa esta amontonada junto a la "
"pared que tienes a mano derecha. El aire tiene un olor especial, parece como "
"un olor a lavanda... es extranyo este olor en una ciudad de enanos, seguro "
"que quien lava la ropa debe ser extranjero. Hay una salida al oeste que "
"conduce al patio.\n");

  SetIntSmell("Huele a lavanda... extranyo olor para un enano.\n");

  AddDetail(({"ropa","monton ropa","montones de ropa","monton","montones"}),
"Montones de ropa amontonados junto a la pared este.\n");
  AddExit("oeste",PISO1+"patio8");
}
