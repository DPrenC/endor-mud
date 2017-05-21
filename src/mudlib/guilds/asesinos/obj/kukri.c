#include <combat.h>
#include <properties.h>
#include "path.h"
inherit "/guilds/asesinos/std/weapon";

void create() {
   ::create();
   SetStandard(WT_CUCHILLO,4,P_SIZE_MEDIUM,M_ACERO);
   SetIds( ({"kukri","cuchillo"}) );
   SetAds( ({"un","el","la","una"}) );
   SetShort("un kukri negro");
   SetLong(W("Es un kukri de color negro, una daga curva oriental "
              "muy útil para cortar gargantas.\n"));
   Set(P_GENDER,GENDER_MALE);
   SetPoisoned(0);
}
