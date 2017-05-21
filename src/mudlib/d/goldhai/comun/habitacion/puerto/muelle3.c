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
 SetIntShort("el muelle 3");
 SetIntLong("\
Estás en el muelle 3 del puerto, justo en la mitad de la zona de muelles.\n\
Aquí hacen escala los barcos que recorren la isla. Hay una tabla colgada\n\
que te indica los barcos que paran en esta parte del puerto.\n");
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
ellos están preparandose para amarrar en el puerto mientras que otros ya lo han\n\
hecho o se disponen a salir.\n");

 AddShip(SOTHKORN("sothkorn"));

 AddExit("norte",PUERTO("muelle2"));
 AddExit("sur",PUERTO("muelle4"));

 SetLocate("puerto de Goldhai");
}
