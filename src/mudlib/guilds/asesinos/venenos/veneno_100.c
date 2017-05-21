#include "./path.h"
inherit "/guilds/asesinos/obj/poison_vial";

void
create()
{
   ::create();
/************************************************/
/* IMPORTANTE IMPORTANTE IMPORTANTE IMPORTANTE  */
/* No usar la funcion SetIds(string *ids) para  */
/* dar los identificadores a los tubos de vene- */
/* no. Usar la función AddId(string id)         */
/************************************************/
   AddId("tubo");
   AddId("tubo ensayo");
   AddId("tubo de ensayo");

   SetAds(({"un","el"}));
   SetShort("un tubo de ensayo");
   SetLong("Es un pequeño tubo de ensayo de cristal. Tiene una etiqueta "
           "con una calavera y dos huesos cruzados que pone: 'VENENO - "
           "Pureza 100%'.\n");
   SetWeight(50);
   SetFilled(10);
   SetPoisonQuality(100);
}

