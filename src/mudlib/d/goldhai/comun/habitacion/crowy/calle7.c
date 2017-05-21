/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-06-97                |
 |               Ultima Modificacion.. 25-01-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"Llegas a un cruce de la ciudad. La calle es amplia y muy bien iluminada.\n\
Si vas hacia el Norte quizás encuentres algo de tu agrado, en el Oeste hay una\n\
pequeña zona comercial, y hacia el Este llegarás a lo que parece ser la zona\n\
de entrada a la ciudad.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"gente","gentes"}),
"Ves de todo. Gente grande, pequeña, con cara de buena fe, con cara de cruel y\n\
malvado, hombres, mujeres, niños.. o sea, de todo.\n");
 AddDetail("calle",
"Está hecha de baldosas prominentes y si no vas con cuidado te puedes caer.\n");
 AddExit("norte",CROWY("calle5"));
 AddExit("oeste",CROWY("calle8"));
 AddExit("este",CROWY("calle9"));
 SetLocate("crowy");
}