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
   SetFoodMsgs("Te comes un limon.. arggh...\n");
   SetFoodStuff(8);
   SetFoodHeal(3);
   SetShort("un limon");
   SetLong("Es un limon algo verde aun.\n");
   AddId("limon");
   AddId("comida");
   SetWeight(80);
   SetValue(15);
}
