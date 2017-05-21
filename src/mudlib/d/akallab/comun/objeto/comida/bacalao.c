/*
DESCRIPCION  : un trozo de bacalao salado
FICHERO      : /d/akallab/comun/objeto/comida/bacalo.c
MODIFICACION : 02-12-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un trozo de bacalao salado. Esta bueno, pero salado.\n");
   SetFoodStuff(20);
   SetFoodHeal(10);
   SetShort("un trozo de bacalao salado");
   SetLong("Es un trozo de bacalao salado. La sal hace que se conserva en buen estado "
           "durante bastante tiempo.\n");
   SetIds(({"bacalao","trozo de bacalao","food"}));
   SetWeight(100);
   SetValue(50);
}
