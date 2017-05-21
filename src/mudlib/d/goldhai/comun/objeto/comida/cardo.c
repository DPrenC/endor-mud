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
   SetFoodMsgs("Te comes un cardo.\n");
   SetFoodStuff(9);
   SetFoodHeal(3);
   SetShort("un cardo");
   SetLong("Es un cardo.\n");
   AddId("cardo");
   AddId("comida");
   Set(P_GENDER,GENERO_MASCULINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(90);
   SetValue(16);
}
