/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 06-01-98               |
 |               Ultima Modificacion... 16-05-99               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("el puerto oeste de Goldhai");
 SetIntLong("\
Estás situado en la entrada del principal puerto de la isla Goldhai. Desde\n\
aquí podrás viajar a los sitios más insospechados de Simauria por un precio\n\
bastante asequible. Si vas hacia el Este te adentraras en el bosque, hacia el\n\
Sur se encuentran los distintos muelles donde atracan los barcos y en el Norte\n\
están las instalaciones portuarias.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Puedes oir todo el ruido que genera un puerto.\n");
 SetIntSmell("Huele a pescado.\n");

 AddDetail(({"mar","oceano","agua"}),
"El agua está bastante sucia y no es el mejor sitio para bañarse.\n");
 AddDetail(({"puerto"}),
"Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
 AddDetail(({"barco","barcos"}),
"Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de\n\
ellos están preparandose para amarrar en el puerto mientras que otros ya lo han\n\
hecho o se disponen a salir.\n");

 AddExit("norte",PUERTO("puerto2"));
 AddExit("este",BOSCURO("camino_puerto2"));
 AddExit("sur",PUERTO("muelle1"));

 AddItem(PNJ("puerto/gaena"),REFRESH_DESTRUCT);

 SetLocate("puerto de Goldhai");
}
