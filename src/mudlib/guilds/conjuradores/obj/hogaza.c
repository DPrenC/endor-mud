#include "path.h"
#include <properties.h>
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes una hogaza de pan mágico.\n");
   SetFoodStuff(30);
   SetFoodHeal(20);
   SetShort("una hogaza de pan mágico");
   SetLong("Es una hogaza de pan mágico.\n");
   AddId("hogaza");
   AddId("comida");
   AddId("pan");
   AddId("hogaza de pan");
   Set(P_NOSELL,1);
   Set(P_GENDER,GENERO_FEMENINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(200);
   SetValue(0);
}
