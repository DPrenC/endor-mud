/* 
DESCRIPCION  : un trozo de panal de abejas
FICHERO      : /d/akallab/comun/objeto/comida/panal.c
MODIFICACION : 02-12-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit FOOD;

create() {
   if (::create()) return 1;
   SetFoodKind("food");
   SetFoodMsgs("Te metes un trozo de panal de miel en la boca y lo saboreas lentamente. Notas\n"
               "como una miel caliente y de fuerte sabor sale poco a poco de las celdas de cera.\n"
               "Tras sorber toda la miel, escupes lo que queda del panal.\n");
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("un trozo de panal de abejas");
   SetLong(
     "Es un pequenyo trozo de panal de abejas cuyas celdas aun estan llenas de rica\n"
     "miel. El atractivo color y olor dulzon de la miel te hacen la boca agua.\n");
   SetIds(({"panal","panal de abeja","panal de miel","food"}));
   SetWeight(100);
   SetValue(30);
}
