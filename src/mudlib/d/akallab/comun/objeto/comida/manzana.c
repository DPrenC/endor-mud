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
   SetFoodMsgs("Te comes una manzana roja.\n");
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("una manzana");
   SetLong("Es una manzana roja de buen tamanyo.\n");
   AddId("manzana");
   AddId("manzana roja");
   AddId("food");
   SetWeight(100);
   SetValue(20);
}
