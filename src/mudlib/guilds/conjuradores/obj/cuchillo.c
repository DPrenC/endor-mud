#include <combat.h>
#include <properties.h>
inherit "/std/weapon";

void create() {
   ::create();
   SetStandard(WT_CUCHILLO,4,P_SIZE_MEDIUM);
   SetIds( ({"cuchillo","cuchillo curvo"}) );
   SetAds( ({"un","la"}) );
   SetShort("un cuchillo curvo");
   SetLong("\
Es un cuchillo curvo, increíblemente afilado, y de muy buena calidad.\n");
   SetValue(11000);
   SetWeight(600);
   Set(P_GENDER,GENDER_MALE);
}
