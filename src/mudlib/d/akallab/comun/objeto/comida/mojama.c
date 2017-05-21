/*
DESCRIPCION  : un trozo de mojama
FICHERO      : /d/akallab/comun/objeto/comida/mojama.c
MODIFICACION : 02-12-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un trozo de mojama. Tiene un sabor fuerte y salado.\n");
   SetFoodStuff(15);
   SetFoodHeal(8);
   SetShort("un trozo de mojama");
   SetLong(
     "Es un trozo de mojama. Esta carne de atun conservada en salazon tiene un fuerte "
     "sabor y se conserva en buen estado durante bastante tiempo.\n");
   SetIds(({"mojama","trozo de mojama","food"}));
   SetWeight(100);
   SetValue(40);
}
