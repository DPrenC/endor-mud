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
 SetIntShort("una herrer�a");
 SetIntLong("\
Te encuentras dentro de la herreria de la ciudad, un lugar donde no se\n\
descansa para atender de la mejor forma y la m�s eficiente a los clientes.\n\
Un grupo j�venes y veteranos pertenecientes al gremio est�n trabajando con\n\
sus yunques arreglando los desperfectos de armas, corazas y escudos.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("No oyes nada especial o que te recuerde algo.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");
// SetNoShop(1);
 AddDetail(({"jovenes","j�venes","herreros","veteranos","jovenes herreros"}),
"No paran en ning�n momento mientras golpean con sus martillos el metal al\n\
rojo vivo.\n");
 AddExit("este",CROWY("calle8"));

 SetLocate("Crowy");
}