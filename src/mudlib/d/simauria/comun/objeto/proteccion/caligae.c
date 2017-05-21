inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_BOTAS, 0, P_SIZE_GENERIC, M_CUERO);
  SetAds(({"unas","ligeras","de cuero"}));
  AddId(({"armadura","sandalias","caligae"}));
  SetShort("unas caligae");
  SetLong(
"Son unas sandalias con suela de esparto que se atan a los pies mediante\n\
unas engorrosas tiras de cuero. Tienen la suela guarnecida con una hilera\n\
de clavos en forma de 'S'.\n");
  SetResetQuality(95);
  }