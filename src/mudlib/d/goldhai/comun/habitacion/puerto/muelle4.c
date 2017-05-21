/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 06-01-98               |
 |               Ultima Modificacion... 20-02-99               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#define TEMPESTAD  "/d/akallab/comun/transporte/barco/tempestad/tempestad"

inherit PORT;

create()
{
 ::create();
 SetIntShort("el muelle 4");
 SetIntLong("\
Has llegado al muelle número 4 del puerto, un lugar dedicado al atraque de\n\
barcos de pesca y de transporte de mercancias, aunque estos de vez en cuando\n\
también aceptan llevar a pasajeros entre ellos. Puedes seguir recorriendo el\n\
muelle hacia el Norte y el Sur. Hay una tabla colgada.\n");

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

 AddShip(TEMPESTAD);

 AddExit("norte",PUERTO("muelle3"));
 AddExit("sur",PUERTO("muelle5"));

 SetLocate("puerto de Goldhai");
}
