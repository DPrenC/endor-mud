/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.
MODIFICACION : [Ch] 10-11-98 Justificado de caracteres a 80.
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("");
SetIntLong(
"Esta estancia parece la habitacion de alguien, es espaciosa y esta muy\n"
"iluminada debido a la cantidad de espirales fosforescentes que se encuentran\n"
"colgadas de la pared. El polvo se ha aduenyado de ella pero contra todos los\n"
"pronosticos no hay suciedad. Ves una cama bien hecha en un extremo y una mesa\n"
"justo en el centro con dos sillas a cada lado. Hacia el este se encuentra la\n"
"salida al pasillo.\n"
);

AddDetail(({"mesa","sillas","silla","sila","mes"}),
"Ves una mesa de madera bastante gastada por el uso con varios libros encima\n"
"de la misma. Hay dos sillas apoyadas en cada uno de sus extremos parecen\n"
"comodas, pero al igual que la mesa se nota que han recibido mucho uso tambien\n"
"son de madera, aunque el respaldo es de mimbre trenzado.\n"
);

AddDetail(({"cama"}),
"Observas una cama con su cabezal respectivo apoyada contra la pared sur de la\n"
"habitacion. Tiene sabanas, almohada y colcha aunque de tejido basto. Pero una\n"
"vez que te sientas en ella sientes su comodidad.\n"
);

AddDetail(({"espirales","luz","fosforescentes","espiral"}),
"Ves la espiral fosforescente:\n"
"                 x\n"
"                 x\n"
"                 x\n"
"                x\n"
"               x\n"
"              x  x\n"
"             x  x x\n"
"             x x   x\n"
"             x  x   x\n"
"              x    x\n"
"               xxxx\n"
"A simple vista parece un adorno cualquiera a pesar de su brillante luz, su\n"
"particularidad es que esta hecha de Ilasi, una mezcla entre Fosforo, Renio y un\n"
"'ingrediente secreto' que solo los elfos conocen. Se emplea para producir luz,\n"
"aunque hay quien asegura que el Ilasi no es mas que magia.\n"
);

SetIntBright(20);
SetIntNoise(
"Al pasear por la habitacion oyes el sonido de tus pasos resonando\n"
"sobre el suelo de piedra.\n"
);

SetIntSmell("");
SetLocate("");
SetIndoors(1);

AddExit("este",TASOTANO("pasillo4"));

}
void init(){
   ::init();
   add_action("foler","oler");
}
foler(string entrada){
   if(!entrada){
      write(
"Al oler el ambiente respiras tal cantidad de polvo y suciedad que no puedes\n"
"evitar estornudar.\n"
"Attchissss!!!\n"
	   );
   say(
TP->QueryName()+" uele el ambiente.\n"
"De repente "+TP->QueryName()+" pone una cara extranya y estornuda\n"
"ruidosamente! Atttchissss!\n"
      );
      return 1;
   }
}

