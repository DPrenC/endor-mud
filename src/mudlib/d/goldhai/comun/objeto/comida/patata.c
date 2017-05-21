/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 26-12-97                |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>


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
   Set(P_GENDER,GENERO_FEMENINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(90);
   SetValue(14);
}
