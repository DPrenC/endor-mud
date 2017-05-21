#include <combat.h>
#include <properties.h>
inherit "/std/weapon";

void create() {
   ::create();
   SetStandard(WT_CUCHILLO,3,P_SIZE_MEDIUM);
   SetIds( ({"daga","daga dorada"}) );
   SetAds( ({"una","la"}) );
   SetShort("una daga");
   SetLong("\
Es una bonita daga labrada, con incrustaciones, parece bastante util.\n");
   SetValue(8000);
   SetWeight(600);
   Set(P_GENDER,GENDER_FEMALE);
}
