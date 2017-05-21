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
   SetFoodMsgs("Te comes un platano y tiras la piel lejos.\n");
   SetFoodStuff(12);
   SetFoodHeal(6);
   SetShort("un platano");
   SetLong("Es un platano amarillo.\n");
   AddId("platano");
   AddId("comida");
   SetWeight(100);
   SetValue(23);
}
