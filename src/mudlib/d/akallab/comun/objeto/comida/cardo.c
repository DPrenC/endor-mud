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
   SetFoodMsgs("Te comes un cardo.\n");
   SetFoodStuff(9);
   SetFoodHeal(3);
   SetShort("un cardo");
   SetLong("Es un cardo.\n");
   AddId("cardo");
   AddId("comida");
   SetWeight(90);
   SetValue(16);
}
