#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Kilok");
   SetIntLong(
"En esta parte de la calle, se encuentran algunas farolas que iluminan el lugar.\n"
"No hay nada que llame tu atencion salvo el puente que se encuentra a pocos metros "
"hacia el sur.\n");

  AddDetail(({"farolas","algunas farolas"}),
  "Son de color negro e iluminan la calle.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("este",CIUDAD+"kilok9");
  AddExit("sur",CIUDAD+"kilok7");

  SetLocate("Kha-annu");
}
