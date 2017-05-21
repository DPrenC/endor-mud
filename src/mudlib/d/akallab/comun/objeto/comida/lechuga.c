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
   SetFoodMsgs("Te comes una lechuga con bichos y todo.\n");
   SetFoodStuff(13);
   SetFoodHeal(5);
   SetShort("una lechuga");
   SetLong("Es una lechuga con algunos bichos.\n");
   AddId("lechuga");
   AddId("comida");
   SetWeight(130);
   SetValue(21);
}
