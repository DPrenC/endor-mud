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
   SetFoodMsgs("Te comes un platano y tiras la piel lejos.\n");
   SetFoodStuff(12);
   SetFoodHeal(6);
   SetShort("un platano");
   SetLong("Es un platano amarillo.\n");
   AddId("platano");
   AddId("comida");
   Set(P_GENDER,GENERO_MASCULINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(100);
   SetValue(23);
}
