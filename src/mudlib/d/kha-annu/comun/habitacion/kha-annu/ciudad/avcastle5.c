#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Estas en una de las calles principales de Kha-annu, la Avenida del "
"Castillo. Al este puedes ver la entrada de el Castillo desde la calle.\n"
"En este sector de la calle, tienes una perfecta perspectiva de la avenida "
"con toda su majestusidad. Al norte puedes ver un arco que parece llevar a "
"pequeño jardin.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte","./ayuntamiento/ayun1");
  AddExit("este",CIUDAD+"avcastle6");
  AddExit("oeste",CIUDAD+"avcastle4");
  SetLocate("Kha-annu");
}
