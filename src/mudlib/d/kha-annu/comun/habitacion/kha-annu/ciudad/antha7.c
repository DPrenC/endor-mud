#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Esta calle es la mas nordica de la ciudad y transcurre pararela a la Avenida "
"del Castillo, a la que puedes llegar cruzando uno de los callejones que hay "
"a lo largo de la calle o llegando a uno de sus extremos en cualquiera de sus "
"direcciones.\n");
  AddDetail(({"antorchas","antorcha","farolas","farola"}),
  "Simplemente ilumian la calle.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("este",CIUDAD+"antha8");
  AddExit("oeste",CIUDAD+"antha6");

  SetLocate("Kha-annu");
}
