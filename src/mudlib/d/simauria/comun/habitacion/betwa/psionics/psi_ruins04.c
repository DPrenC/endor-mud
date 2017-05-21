/* psi_ruins05.c
   En el jardín del Gremio
   Creación: [n] Nemesis, 11-Abr-2001 1:17:19 CEST

*/

#include "./path.h"
inherit SIM_ROOM;

int beber(string arg) {
  if (arg == "agua" || arg == "de la fuente" || arg == "de fuente")
  {
   write("El agua está muy fría, pero está muy buena.\n");
   TP->SetDrink(TP->QueryDrink()+1);
   return 1;
  }
  else
   return 0;
}


create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un pequeño atrio");
SetIntLong(
W("Has llegado a lo que una vez fue un pequeño atrio con una fuente. Como en\
 el resto del jardín, la antigua cúpula de cristal que lo cubría está\
 resquebrajada y rota en muchos puntos, y hay trozos de cristal por todo el\
 suelo que crujen a tu paso. La fuente está desgastada por el tiempo y cubierta\
 de hojas secas, sin embargo, los pájaros acuden aquí a beber y las flores\
 no se han marchitado todavía. Sin duda éste era un lugar especial, un lugar\
 de paz.\n\
El jardín continúa hacia el norte y el este, mientras que un arco conduce\n\
al exterior hacia el sur.\n" ));
SetIndoors(1);
SetIntNoise("Oyes el alegre sonido del agua de la fuente.\n");

AddDetail(({"cubierta","techo","cúpula","cupula"}),
"Está muy deteriorada, aunque el frío del exterior no parece capaz de "
"penetrar por los enormes agujeros que tiene.\n");
AddDetail(({"jardín","jardin"}),
"A pesar del frío intenso que reina en la cumbre de la montaña, el jardín no "
"se ha marchitado.\n");
AddDetail(({"cristales","cristales rotos"}),
"Hay restos del techo de cristal por todas partes.\n");
AddDetail(({"flores","flores multicolores"}),
"Aquí crecen todo tipo de flores hermosas. Te preguntas cómo es posible.\n");
AddDetail(({"pájaros","pajaros"}),
"Hay muchos pájaros de especies diferentes.\n");
AddDetail(({"fuente","pequeña fuente","pequenya fuente"}),
"De la fuente surge un refrescante chorro de agua.\n");
AddDetail(({"chorro","chorro de agua","agua"}),
"Parece un agua muy pura. Debe venir de algún manantial de las montañas. "
"Casi te dan ganas de probar un trago.\n");

AddRoomCmd("beber",SF(beber));

AddExit("norte","psi_ruins05");
AddExit("sur","psi_ruins06");
AddExit("este","psi_ruins03");

}