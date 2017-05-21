/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 29-10-98                |
 |               Ultima Modificacion... 29-10-98                |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>


inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un asquerosa junka.. y sin cocinar.\n");
   SetFoodStuff(9);
   SetFoodHeal(3);
   SetShort("una junka");
   SetLong("\
Las junkas son unos pequenyos peces que se crian en las costas de Goldhai. Su\n\
color suele ser muy oscuro y tienen una asquerosa boca alargada.\n");
   AddId("junka");
   AddId("comida");
   AddId("pescado");
   Set(P_GENDER,GENERO_FEMENINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(600);
   SetValue(10);
   SetSmell("Huele a junca... un olor indefinible.\n");

}
