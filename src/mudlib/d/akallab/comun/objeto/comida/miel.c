/* 
DESCRIPCION  : un tarro de miel
FICHERO      : /d/akallab/comun/objeto/comida/miel.c
MODIFICACION : 02-12-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit FOOD;

create() {
   if (::create()) return 1;
   SetFoodKind("food");
   SetFoodMsgs("Te comes el contenido de un tarro de miel. Esta tan dulce y buena que te quedas\n"
               "con ganas de mas...\n");
   SetFoodStuff(20);
   SetFoodHeal(8);
   SetShort("un tarro de miel");
   SetLong(
     "Es un pequenyo tarro lleno de miel de flores. Su color, un marron oscuro\n"
     "semitranslucido, y su olor dulzon te hacen la boca agua.\n");
   SetIds(({"miel","tarro de miel"}));
   SetWeight(150);
   SetValue(50);
}
