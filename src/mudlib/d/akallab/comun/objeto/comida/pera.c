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
   SetFoodMsgs("Te comes una pera.\n");
   SetFoodStuff(8);
   SetFoodHeal(4);
   SetShort("una pera");
   SetLong("Es una pera de agua.\n");
   AddId("pera");
   AddId("comida");
   SetWeight(80);
   SetValue(16);
}
