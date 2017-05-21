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
   SetFoodMsgs("Te comes una col fresca.\n");
   SetFoodStuff(30);
   SetFoodHeal(9);
   SetShort("una col fresca");
   SetLong("Es una col fresca.\n");
   AddId("col");
   AddId("comida");
   SetWeight(350);
   SetValue(65);
}
