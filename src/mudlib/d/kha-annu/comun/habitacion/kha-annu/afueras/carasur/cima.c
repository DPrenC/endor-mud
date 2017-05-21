/* Cima de la Montanya, a donde se accede desde el camino entre */
/* Kha-annu y Flenton. Creado por [Y] Yandros en Junio de 1999  */
#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

  SetIntShort("la cima de las Montañas de Kha-annu");
   SetIntLong(
"Te encuentras en la cima de las Montañas de Kha-annu, desde donde puedes "
"ver los alrededores de la zona. Hacia el norte, sabes que se encuentra la "
"ciudad de Kha-annu y hacia el suroeste la aldea de Flenton. Una inmensa "
"llanura se extiende hacia el oeste la cual es inaccesible desde este punto.\n");

   SetIndoors(0);

}
