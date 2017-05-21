#include "./path.h"
inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la ladera de la Montaña de Kha-Annu.");
   SetIntLong(
"Aun estando cerca de la falda de la Montanya, la altura que has conseguido escalar "
"merece tener cierta consideracion. Sería cnmveniente seguir escalando hasta un "
"lugar mas seguro o descender a suelo firme.\n");
   SetIndoors(0);
   SetLocate("Camino de Kha-Annu");
}