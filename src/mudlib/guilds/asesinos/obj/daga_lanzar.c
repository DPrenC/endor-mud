#include <combat.h>
#include <properties.h>
#include "path.h"
inherit "/guilds/asesinos/std/weapon";

void create() {
   ::create();
   SetStandard(WT_CUCHILLO, 3, P_SIZE_MEDIUM);
   SetIds( ({"daga","daga lanzar","daga de lanzar"}) );
   SetAds( ({"una","la"}) );
   SetShort("una daga de lanzar");
   SetLong("Una util daga de lanzar, ligera pero bien equilibrada.\n");
   Set(P_GENDER,GENDER_FEMALE);
   Set(P_NOEQUIP, "No puedes empunyar una daga destinada para ser lanzada.\n");
   SetPoisoned(0);
}
