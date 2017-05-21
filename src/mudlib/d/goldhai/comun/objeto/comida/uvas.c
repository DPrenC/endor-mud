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
   SetFoodMsgs("Te comes un racimo completo de uvas.\n");
   SetFoodStuff(11);
   SetFoodHeal(6);
   SetShort("un racimo de uvas");
   SetLong("Es un racimo bastante hermoso de uvas.\n");
   AddId("uva");
   AddId("uvas");
   AddId("racimo");
   AddId("racimo de uvas");
   AddId("comida");
   Set(P_GENDER,GENERO_FEMENINO);
   Set(P_NUMBER,NUMERO_PLURAL);
   SetWeight(120);
   SetValue(32);
}
