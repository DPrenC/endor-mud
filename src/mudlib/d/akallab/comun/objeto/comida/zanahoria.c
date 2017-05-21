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
   SetFoodMsgs("Te comes una zanahoria.. te pareces a un conejo.\n");
   SetFoodStuff(7);
   SetFoodHeal(2);
   SetShort("una zanahoria");
   SetLong("Es una zanahoria.\n");
   AddId("zanahoria");
   AddId("comida");
   SetWeight(65);
   SetValue(11);
}
