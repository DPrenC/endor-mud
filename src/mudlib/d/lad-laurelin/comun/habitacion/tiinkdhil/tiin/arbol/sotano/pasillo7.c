/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION : [Ch] Chantiel
               [Ch] 6-10-96 Ajuste de texto a 80 caracteres.
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("");
SetIntLong(
"La estancia es muy amplia, pero cuando miras al techo y a las paredes te\n"
"sientes fascinado ya que estan formadas por miles de delgadas raices\n"
"entrelazadas entre ellas, de tal forma que no puedes saber con certeza su\n"
"comienzo y su fin. Las espirales fosforescentes estan incrustadas entre los\n"
"huecos que dejan, pero algunas raicillas estan por encima, por eso la luz\n"
"aqui es bastante pobre. Al este y al sur hay celdas. El pasillo sigue hacia\n"
"el norte y hacia el oeste.\n"
);

AddDetail (({"","",""}),"");
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
"particularidad es que esta hecha de Ilasi, una mezcla entre Fosforo, Renio\n"
"y un 'ingrediente secreto' que solo los elfos conocen. Se emplea para producir\n"
"luz, aunque hay quien asegura que el Ilasi no es mas que magia.\n"
);

SetIntBright(20);
SetIntNoise("Puedes oir pasos lejanos.\n");
SetIntSmell("El olor a humedad empapa toda la estancia.\n");
SetLocate("");
SetIndoors(1);

AddExit("norte",TASOTANO("pasillo5"));
AddExit("sur",TASOTANO("celda9"));
AddExit("este",TASOTANO("celda7"));
AddExit("oeste",TASOTANO("pasillo6"));

}

void init(){
  ::init();
  add_action("foler","oler");
}

int foler()
{
  write(
"Al oler el ambiente respiras tal cantidad de polvo y suciedad que no puedes\n"
"evitar estornudar....\n"
"Atttchissss!!!\n"
      );
  say(
TP->QueryName()+" huele el ambiente.\n"
"De repente "+TP->QueryName()+" pone una cara extranya y estornuda ruidosamente!\n"
"Atttchiss!\n"
);
  return 1;
}
