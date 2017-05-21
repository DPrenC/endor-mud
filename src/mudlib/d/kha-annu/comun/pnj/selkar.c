/* Creado por [I] Izet@Simauria.
  Modificado por [Y] Yandros
  [Woo] Modificado
*/


#include "path.h"
#include <properties.h>


inherit KBASE;

object pipa;

create() {
  ::create();
  SetStandard("Selkar","enano",11,GENDER_MALE);
  SetShort("Selkar, el herbolario");
  SetLong(
"Selkar es un viejo enano que se dedica a la recolección y venta de plantas y\n"
"hierbas, según dice él, con fines medicinales. Su rostro está cubierto por una\n"
"gran barba de color blanco y está fumando en pipa.\n");
  SetAggressive(0);
  SetWeight(55000);
  SetAlign(160);
  SetWhimpy(0);
  SetIds(({"selkar","selkar el herbolario","herbolario"}));
  InitChats(1,({
   "Selkar fuma de la pipa y se pone a hacer anillos de humo.\n"}));
}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"Selkar cae rodando al suelo y suelta la pipa de su mano.\n"
);
   pipa=clone_object(OTRO("pipa"));
pipa->move(environment(TO));
   ::Die(silent);
}

init() {
  ::init();
  add_action("matar","matar");
}

int matar(string str) {
  if ( (str == "selkar") || (str == "herbolario") ) {
    tell_room(environment(TO),"Selkar se pone a dar gritos de auxilio.\n");
    /* cloner un guardia */
    return 0;
  } else {
    return 0;
  }
}
