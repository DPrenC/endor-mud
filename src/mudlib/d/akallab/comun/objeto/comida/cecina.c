/*
DESCRIPCION  : un trozo de cecina de cerdo
FICHERO      : /d/akallab/comun/objeto/comida/cecina.c
MODIFICACION : 02-12-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un trozo de cecina. Tiene un sabor fuerte y salado.\n");
   SetFoodStuff(18);
   SetFoodHeal(10);
   SetShort("un trozo de cecina de cerdo");
   SetLong(
     "Es un trozo de cecina de cerdo. Esta carne conservada en salazon tiene un fuerte "
     "sabor y se conserva en buen estado durante bastante tiempo.\n");
   SetIds(({"cecina","trozo de cecina","food"}));
   SetWeight(100);
   SetValue(45);
}
