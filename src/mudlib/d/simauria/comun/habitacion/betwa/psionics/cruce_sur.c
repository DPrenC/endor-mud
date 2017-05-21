/* cruce_sur.c
   Camino hacia el Gremio de Psiónicos
   Creación: [n] Nemesis, 10-Abr-2001 23:54:31 CEST
   NOTA: Podría ser el inicio del camino a la tumba de Gnudur
         (Quest del Secreto del Acero)
*/

#include <colours.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("fin de");
SetIntShort("el ramal");
SetIntLong(
"Estás frente a una pared basáltica. No comprendes muy bien la razón de\
 construir un camino que conduce directamente a una pared, aunque también\
 podría ser que una convulsión tectónica bloqueara el camino. En cualquier\
 caso, lo cierto es que sólo puedes ir hacia el norte.\n");
SetIndoors(0);

AddDetail(({"pared","pared basáltica","pared basaltica"}),
"Se trata de uno de los flancos de la montaña. No puedes trepar ni rodearla, "
"así que lo mejor es que vuelvas sobre tus pasos.\n");

AddExit("norte","camino05");

}
