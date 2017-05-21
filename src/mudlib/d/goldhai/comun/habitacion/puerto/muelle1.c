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
 SetIntShort("el muelle 1");
 SetIntLong("\
Te encuentras en el muelle 1 del principal puerto de Goldhai, un lugar donde\n\
los barcos atracan procedentes de los m�s reconditos lugares de Simauria.\n\
Apostado en la orilla del muelle se puede divisar el resto del puerto as� como\n\
el ir y venir de barcos. Si vas hacia el Norte saldr�s de la zona de muelles\n\
mientras que si vas al Sur llegar�s al muelle 2. Hay una tabla colgada donde\n\
podr�s ver los barcos que atracan en este muelle.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Puedes oir todo el ruido que genera un puerto.\n");
 SetIntSmell("Huele a pescado.\n");

 AddDetail(({"mar","oceano","agua"}),
"El agua est� bastante sucia y no es el mejor sitio para ba�arse.\n");
 AddDetail(({"muelle"}),
"El muelle est� todo hecho a base de grandes maderos y es bastante deslizante.\n");
 AddDetail(({"puerto"}),
"Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
 AddDetail(({"barco","barcos"}),
"Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de\n\
ellos est�n preparandose para amarrar en el puerto mientras que otros ya lo han\n\
hecho o se disponen a salir.\n");

 AddExit("norte",PUERTO("puerto1"));
 AddExit("sur",PUERTO("muelle2"));

 SetLocate("puerto de Goldhai");
}
