/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("un parque");
 SetIntLong(
"El parque en el que te encuentras está situado justo en el centro de Crowy.\n\
Cuatro arboles enormes en cada una de las esquinas dan sombra en los dias\n\
calurosos y permiten que los más pequeños se diviertan trepando por ellos.\n\
Sin duda es el mejor sitio para echar una cabezadita o descansar. Puedes salir\n\
de aquí yendo al Este o al Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntBright(30);
 SetIntNoise("Si te fijas mucho puedes escuchar a los pajaros.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"jardin","parque","zona relax"}),
"Una zona verde en la que poder descansar cubierta de una hierba suave. Hay\n\
unos cuantos monticulos de tierra en donde los más jovenes simulan ser\n\
grandes guerreros. Cuatro arboles de unos 100 pies de altura protegen el\n\
terreno de las grandes lluvias y sus copas se llenan de nieve cuando nieva.\n");
 AddDetail(({"arbol","arboles"}),
"Situados en cada uno de los extremos del parque dan un toque muy particular\n\
a este lugar. Los niños trepan por ellos para poder ver toda la ciudad.\n");
 AddExit("sur",CROWY("calle9"));
 AddExit("este",CROWY("calle13"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(3)+1);

 SetLocate("crowy");
}
