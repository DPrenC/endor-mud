/*
DESCRIPCION  : una cebolla
FICHERO      : /d/akallab/comun/objeto/comida/cebolla.c
MODIFICACION : 16-09-01 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Pelas la cebolla y te la comes al tiempo que te lloran los ojos...\n");
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("una cebolla");
   SetLong("Es una cebolla de mediano tamaño.\n");
   AddId("cebolla");
   AddId("comida");
   SetWeight(100);
   SetValue(25);
}
