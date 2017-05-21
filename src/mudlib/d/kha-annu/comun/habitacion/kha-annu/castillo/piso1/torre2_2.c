/* Created by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria, para implementar a Nightfall(tm).
   Ultima modificacion: 10 Oct, 1997.
 */
#include "path.h"
inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("un puesto de vigilancia en la Torre del Noroeste");

SetIntLong(
"Has subido hasta el puesto de vigilancia de la Torre del Noroeste del "
"castillo. Desde aqui tienes una magnifica vista de las montanyas y las colinas "
"circundantes.\n");

SetIntBright(90);

SetIndoors(1);

AddExit("abajo", PISO1+"torre2_1");

AddDetail(({"montanyas","montanya"}),
"Desde aqui puedes ver una pequenya cadena montanyosa situada hacia el "
"noroeste de esta torre.\n");
AddDetail(({"colina","colinas"}),
"Antes de la cadena montanyosa ves las colinas, lugar perfecto para acampar.\n");
}