/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 27-04-97                |
 |               Ultima Modificacion.. 23-09-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"

inherit SMITHY;

create()
{
 ::create();
 SetIntShort("una herrería");
 SetIntLong("\
Te encuentras dentro de la herreria de la ciudad, un lugar donde no se\n\
descansa para atender de la mejor forma y la más eficiente a los clientes.\n\
Un grupo jóvenes y veteranos pertenecientes al gremio están trabajando con\n\
sus yunques arreglando los desperfectos de armas, corazas y escudos.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("No oyes nada especial o que te recuerde algo.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");
// SetNoShop(1);
 AddDetail(({"jovenes","jóvenes","herreros","veteranos","jovenes herreros"}),
"No paran en ningún momento mientras golpean con sus martillos el metal al\n\
rojo vivo.\n");
 AddExit("este",CROWY("calle8"));

 SetLocate("Crowy");
}