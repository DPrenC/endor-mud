/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 26-12-97                |
 |                                                             |
 *=============================================================*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes una patata.. sin cocinar la encuentras rara.\n");
   SetFoodStuff(10);
   SetFoodHeal(3);
   SetShort("una patata");
   SetLong("Es una patata.\n");
   AddId("patata");
   AddId("comida");
   SetWeight(90);
   SetValue(14);
}
