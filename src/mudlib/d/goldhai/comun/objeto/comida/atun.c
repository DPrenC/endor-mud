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
   SetFoodMsgs("Te comes un atun.\n");
   SetFoodStuff(9);
   SetFoodHeal(3);
   SetShort("un atun");
   SetLong("\
Los atunes resultan muy dificiles de capturar pero tienen un sabor delicioso.\n");
   AddId("atun");
   AddId("comida");
   AddId("pescado");
   Set(P_GENDER,GENERO_MASCULINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(2000);
   SetValue(30);
   SetSmell("uhm... huele a pescado.\n");

}
