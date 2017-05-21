/* Esto es dentro de la diligencia */

#include "path.h"
inherit KHA_ROOM;

create() {
  ::create();
  SetPreIntShort("dentro de");
  SetIntShort("la diligencia");
  SetIntLong(
"Te encuentras en el interior de la diligencia que va desde Kha-annu hasta\n"
"Nandor. No hay nada especial aqui adentro.\n");

}