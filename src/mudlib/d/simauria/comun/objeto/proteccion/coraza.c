inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_CORAZA,10,P_SIZE_GENERIC,M_HIERRO);
 AddId("coraza");
 AddAdjective("de hierro");
 SetShort("una coraza");
 SetLong("Es una coraza de hierro. Es un trabajo algo tosco, pero cumple su cometido.\n");
 Set(P_GENDER,GENDER_FEMALE);
 SetResetQuality(90);
}


