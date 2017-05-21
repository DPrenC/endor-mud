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
   SetFoodMsgs("Te comes una naranja.\n");
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("una naranja");
   SetLong("Es una naranja, una simple naranja.\n");
   AddId("naranja");
   AddId("comida");
   Set(P_GENDER,GENERO_FEMENINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(100);
   SetValue(25);
}
