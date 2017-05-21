#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Aqui comienza la avenida del castillo, a lo largo y ancho de la calle puedes "
"ver enanos paseando por la ciudad o en sus que haceres. Aqui las fachadas de "
"los edificios son algo mas lujosas, los grabados parecen de mayor calidad y "
"los adornos mas sofisticados. En esta avenida se encuentra la entrada al "
"castillo.\n");

   SetIntBright(80);
   SetIndoors(1);
 SetIntNoise("No huele a nada en especial.\n");
 SetIntSmell("Oyes todo tipo de ruidos tipicos de la ciudad.\n");

 AddDetail(({"fachada","fachadas"}),
 "Las fachadas de los edificios que hay aqui estan lujosamente talladas.\n"
 "La talla es fina, llenando de formas los muros, casi simpre decorativas, otras "
 "sin mucho sentido. Alguien ha pagado a un artesano durante mucho tiempo.\n");

  AddItem(MONS+"amacasa",REFRESH_DESTRUCT,1);
  AddExit("este",CIUDAD+"avcastle2");
  AddExit("oeste",CIUDAD+"rurik8");
  SetLocate("Kha-annu");
}
