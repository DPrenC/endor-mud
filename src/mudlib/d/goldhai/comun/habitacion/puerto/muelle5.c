/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 25-10-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PORT;

create()
{
 ::create();
 SetIntShort("el muelle 5");
 SetIntLong("\
Te encuentras justo en el muelle 5 del puerto, un lugar donde no hacen escala\n\
ningun tipo de barco comercial, esta dedicado exclusivamente para los barcos\n\
de los piratas y traficantes de los mares. Hay una tabla colgada de un poste.\n\
Los muelles continuan en direccion Norte y Sur.\n");

 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Puedes oir todo el ruido que genera un puerto.\n");
 SetIntSmell("Huele a pescado.\n");

 AddDetail(({"mar","oceano","agua"}),
"El agua esta bastante sucia y no es el mejor sitio para banyarse.\n");
 AddDetail(({"muelle"}),
"El muelle esta todo hecho a base de grandes maderos y es bastante deslizante.\n");
 AddDetail(({"puerto"}),
"Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
 AddDetail(({"barco","barcos"}),
"Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de\n\
ellos estan preparandose para amarrar en el puerto mientras que otros ya lo han\n\
hecho o se disponen a salir.\n");

 AddExit("norte",PUERTO("muelle4"));
 AddExit("sur",PUERTO("muelle6"));

 SetLocate("puerto de Goldhai");
}
