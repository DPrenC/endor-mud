inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_HELMET,1,P_SIZE_MEDIUM);
 AddId("casco");
 AddAdjective("abollado");
 SetShort("un casco");
 SetLong(
   "Es un casco abierto y sin visera. El material no parece muy bueno y además está\n"
   "un poco abollado, sin duda debido a usos anteriores.\n");
  SetResetQuality(90);

}




