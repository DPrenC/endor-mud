/*
DESCRIPCION  : un trozo de salmon ahumado
FICHERO      : /d/akallab/comun/objeto/comida/salmon_ahumado.c
MODIFICACION : 02-12-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un trozo de salmon ahumado. Gran sabor con un toque ahumado.\n");
   SetFoodStuff(22);
   SetFoodHeal(11);
   SetShort("un trozo de salmon ahumado");
   SetLong("Es un trozo de salmon ahumado. El secado y ahumado de este pescado hace que se "
           "conserva en buen estado durante bastante tiempo.\n");
   SetIds(({"salmon","trozo de salmon","food"}));
   SetWeight(100);
   SetValue(55);
}
