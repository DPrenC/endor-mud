/* psi_ruins05.c
   En el jard�n del Gremio
   Creaci�n: [n] Nemesis, 11-Abr-2001 1:17:19 CEST

*/

#include "./path.h"
inherit SIM_ROOM;

int beber(string arg) {
  if (arg == "agua" || arg == "de la fuente" || arg == "de fuente")
  {
   write("El agua est� muy fr�a, pero est� muy buena.\n");
   TP->SetDrink(TP->QueryDrink()+1);
   return 1;
  }
  else
   return 0;
}


create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un peque�o atrio");
SetIntLong(
W("Has llegado a lo que una vez fue un peque�o atrio con una fuente. Como en\
 el resto del jard�n, la antigua c�pula de cristal que lo cubr�a est�\
 resquebrajada y rota en muchos puntos, y hay trozos de cristal por todo el\
 suelo que crujen a tu paso. La fuente est� desgastada por el tiempo y cubierta\
 de hojas secas, sin embargo, los p�jaros acuden aqu� a beber y las flores\
 no se han marchitado todav�a. Sin duda �ste era un lugar especial, un lugar\
 de paz.\n\
El jard�n contin�a hacia el norte y el este, mientras que un arco conduce\n\
al exterior hacia el sur.\n" ));
SetIndoors(1);
SetIntNoise("Oyes el alegre sonido del agua de la fuente.\n");

AddDetail(({"cubierta","techo","c�pula","cupula"}),
"Est� muy deteriorada, aunque el fr�o del exterior no parece capaz de "
"penetrar por los enormes agujeros que tiene.\n");
AddDetail(({"jard�n","jardin"}),
"A pesar del fr�o intenso que reina en la cumbre de la monta�a, el jard�n no "
"se ha marchitado.\n");
AddDetail(({"cristales","cristales rotos"}),
"Hay restos del techo de cristal por todas partes.\n");
AddDetail(({"flores","flores multicolores"}),
"Aqu� crecen todo tipo de flores hermosas. Te preguntas c�mo es posible.\n");
AddDetail(({"p�jaros","pajaros"}),
"Hay muchos p�jaros de especies diferentes.\n");
AddDetail(({"fuente","peque�a fuente","pequenya fuente"}),
"De la fuente surge un refrescante chorro de agua.\n");
AddDetail(({"chorro","chorro de agua","agua"}),
"Parece un agua muy pura. Debe venir de alg�n manantial de las monta�as. "
"Casi te dan ganas de probar un trago.\n");

AddRoomCmd("beber",SF(beber));

AddExit("norte","psi_ruins05");
AddExit("sur","psi_ruins06");
AddExit("este","psi_ruins03");

}