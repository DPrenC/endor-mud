#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"La avenida continua de este a oeste, con su particular esplendor de capital "
"enana. Aqui encuentras un callejon en mitad de la avenida mas importante, que "
"sin duda le quita atractivo a la calle, pero tal vez lleve a algun sitio "
"interesante. Si esta por algo sera.\n");

   SetIntBright(80);
   SetIndoors(1);
 SetIntNoise("No oyes nada, del otro mundo.\n");
 SetIntSmell("Una serie de olorcillos salen del callejon\n");

  AddExit("norte",CIUDAD+"tiendas/trasera");
  AddExit("este",CIUDAD+"avcastle3");
  AddExit("oeste",CIUDAD+"avcastle1");
  AddExit("sur",CIUDAD+"hunkas7");
  SetLocate("Kha-annu");
}
