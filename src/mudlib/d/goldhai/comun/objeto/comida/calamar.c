/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 29-10-98               |
 |               Ultima Modificacion... 29-10-98               |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>


inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un calamar y te pringas con su tinta.\n");
   SetFoodStuff(9);
   SetFoodHeal(3);
   SetShort("un calamar");
   SetLong("Se trata de un bonito calamar pescado cerca de Goldhai.\n");
   AddId("calamar");
   AddId("comida");
   AddId("pescado");
   Set(P_GENDER,GENERO_MASCULINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(100);
   SetValue(20);
   SetSmell("uhm... huele a pescado.\n");
}
