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
   SetFoodMsgs("Te comes unas espinacas.\n");
   SetFoodStuff(8);
   SetFoodHeal(5);
   SetShort("unas espinacas");
   SetLong("Es un manojo de estupendas espinacas verdes.\n");
   AddId("espinaca");
   AddId("espinacas");
   AddId("comida");
   SetWeight(80);
   SetValue(18);
}
