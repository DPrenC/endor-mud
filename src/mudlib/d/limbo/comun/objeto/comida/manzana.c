/*
1997-12-26 [Woo] Creacion
2008-09-14 [Angor] Modificacion
*/

#include "path.h"
inherit FOOD;
#include <properties.h>

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes una manzana roja.\n");
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("una manzana");
   SetLong("Es una manzana roja de buen tamaño.\n");
   AddId("manzana");
   AddId("manzana roja");
   AddId("food");
   SetWeight(100);
   SetValue(20);
   Set(P_NOSELL,1);
}
