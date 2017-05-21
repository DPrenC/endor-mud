/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 06-01-98               |
 |               Ultima Modificacion... 20-02-99               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PORT;

create()
{
 ::create();
 SetIntShort("el muelle 6");
 SetIntLong("\
Estás situado en el muelle 6, desde aquí se puede divisar hacia el norte\n\
todo este puerto. Si quieres ir a algún lugar en concreto de Simauria este\n\
es uno de los mejores medios para viajar de una forma rápida y económica. Si\n\
continuas hacia el Norte llegarás al muelle 5 mientras que si lo que deseas\n\
es salir del puerto puedes ir en direccion Este. Hay una tabla colgada que\n\
indica los barcos que hacen escala en esta parte del puerto.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Puedes oir todo el ruido que genera un puerto.\n");
 SetIntSmell("Huele a pescado.\n");

 AddDetail(({"mar","oceano","agua"}),
"El agua está bastante sucia y no es el mejor sitio para bañarse.\n");
 AddDetail(({"muelle"}),
"El muelle está todo hecho a base de grandes maderos y es bastante deslizante.\n");
 AddDetail(({"puerto"}),
"Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
 AddDetail(({"barco","barcos"}),
"Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de\n\
ellos estan preparandose para amarrar en el puerto mientras que otros ya lo han\n\
hecho o se disponen a salir.\n");

 AddExit("norte",PUERTO("muelle5"));
 AddExit("este",BOSCURO("camino_puerto4"));

 SetLocate("puerto de Goldhai");
}
