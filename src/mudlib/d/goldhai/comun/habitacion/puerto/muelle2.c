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
 SetIntShort("el muelle 2");
 SetIntLong("\
Estás en el muelle 2 del puerto oeste de Goldhai. Desde aquí seguro que\n\
podrás coger algun barco que te lleve a tu destino. Puedes seguir recorriendo\n\
los muelles en dirección Norte y Sur. Hay una tabla donde vienen indicados\n\
los barcos que hacen escala en esta parte del puerto.\n");
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

 AddShip(BENOSHAN("benoshan"));

 AddExit("norte",PUERTO("muelle1"));
 AddExit("sur",PUERTO("muelle3"));

 SetLocate("puerto de Goldhai");
}
