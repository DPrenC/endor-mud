/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.
MODIFICACION : [Ch] 11-10-97 Ajuste de 80 caracteres.
*/


#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un calabozo del Arbol de la Vida");
SetIntLong(
"Que pequenya!!! Sin duda esta es una celda para gente diminuta, pero\n"
"agachandote y casi reptando logras entrar. Mejor no lo hubieras hecho, del\n"
"techo y las paredes salen raices pequenyas recubiertas de tierra, que dejan\n"
"caer, poco a poco, arenilla al suelo, levantando polvo en suspension que te\n"
"hace estornudar. Por el suelo hay mucha paja y suciedad. La salida que hay\n"
"al pasillo queda al oeste.\n"
);

AddDetail(({"paja","heno","monton"}),
"Ves un monton de paja normal y corriente, pero muy sucia situada en un\n"
"extremo de la celda y puesta de cualquier forma.\n"
);

SetIntBright(10);
SetIntNoise("Desde el pasillo llegan amortiguados pasos hasta la habitacion.\n");
SetLocate("");
SetIndoors(1);

AddExit("oeste",TASOTANO("pasillo7"));

}
void init(){
  ::init();
  add_action("foler","oler");
}

int foler(string entrada)
{
 if (!entrada){
  write(
"Al oler el ambiente respiras tal cantidad de polvo y suciedad que no puedes\n""evitar estornudar....\n"
"Atttchissss!!!\n"
      );
  say(
TP->QueryName()+" huele el ambiente.\n"
"De repente "+TP->QueryName()+" pone una cara extranya y estornuda\n"
"ruidosamente! Atttchiss!\n"
);
  return 1;
 }
}