/*
 No se de quien es esto, pero le voy a cortar algo. Se le olvido el detalle
 de poner una salida al norte a freya2. Os voy a asesinar!

 Nemesis

 */

#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Te encuentras en la calle Antharax, con un callejon hacia el sur que llega "
"a la Avenida del Castillo. Al norte esta la calle Freya que lleva a la "
"puerta norte de Kha-annu. Varias farolas iluminan la calle.\n");
  AddDetail(({"farolas","farola"}),
  "De color negro. Estan para iluminar las calles.\n");
  AddDetail(({"callejon"}),
  "Lo veras mejor si entras en el.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"puertanor/freya2");
  AddExit("sur",CIUDAD+"callejon9");
  AddExit("este",CIUDAD+"antha7");
  AddExit("oeste",CIUDAD+"antha5");

  SetLocate("Kha-annu");
}
