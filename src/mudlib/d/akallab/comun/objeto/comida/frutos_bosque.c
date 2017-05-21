/*
DESCRIPCION  : un punyado de frutos del bosque
FICHERO      : /d/akallab/comun/objeto/comida/frutos_bosque.c
MODIFICACION : 11-12-99 [Angor@Simauria] Creacion.
*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un punyado de frutos del bosque. Estan dulces y sabrosos.\n");
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("un punyado de frutos del bosque");
   SetLong("Es un punyado de frutos del bosque: moras, bayas, cerezas, ...\n");
   AddId("frutos");
   AddId("frutos del bosque");
   AddId("food");
   SetWeight(100);
   SetValue(10);
}
