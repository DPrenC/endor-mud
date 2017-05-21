#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Continuas por la lujosa avenida del castillo. Puedes observar que hasta las "
"las farloras son mas lujosas que en otras partes de la ciudad.\n"
"Es por eso que es puedan haber guardias en esta zona, aunque los enanos no "
"se roban entre ellos, pero cualquier extraño puede tener tentaciones.\n"
"La calle continua de este a oeste.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

  AddExit("este",CIUDAD+"avcastle4");
  AddExit("oeste",CIUDAD+"avcastle2");
  SetLocate("Kha-annu");
}
