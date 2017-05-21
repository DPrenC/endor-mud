/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 16-02-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"La calle, lugar de paso pero no de estancia, sitio donde estar pero no\n\
permanecer. Con su gente que anda sin saber muy bien a donde ir. En el Oeste\n\
hay una zona comercial donde igual puedes encontrar aquello que andas buscando\n\
y no habias encontrado. La calle continua hacia el Norte y el Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"gente","gentes"}),
"Ves de todo. Gente grande, pequeña, con cara de buena fe, con cara de cruel y\n\
malvado, hombres, mujeres, niños.. o sea, de todo.\n");
 AddDetail("calle",
"Esta hecha de baldosas prominentes y si no vas con cuidado te puedes caer.\n");
 AddExit("norte",CROWY("calle2"));
 AddExit("este",CROWY("taquillas"));
 AddExit("oeste",CROWY("calle4"));
 AddExit("sur",CROWY("calle5"));
 SetLocate("crowy");
}