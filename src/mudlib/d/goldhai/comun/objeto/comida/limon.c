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
   SetFoodMsgs("Te comes un limon.. arggh...\n");
   SetFoodStuff(8);
   SetFoodHeal(3);
   SetShort("un limon");
   SetLong("Es un limon algo verde aun.\n");
   AddId("limon");
   AddId("comida");
   Set(P_GENDER,GENERO_MASCULINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(80);
   SetValue(15);
}
