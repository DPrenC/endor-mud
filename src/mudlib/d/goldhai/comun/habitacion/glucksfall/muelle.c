/*=============================================================*
 |          << GOLDHAI.Glucksfall [w] Woo@simauria >>          |
 *=============================================================*
 |             Creacion.................. 23-08-98             |
 |             Ultima Modificacion....... 05-10-98             |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PORT;

create()
{
 ::create();
 SetIntShort("el puerto de Glucksfall");
 SetIntLong("\
Estás en el puerto de Glucksfall, un sitio bastante sucio y asqueroso, pero\n\
que no importa a la gente que suele venir aquí, contrabandistas, salteadores,\n\
piratas, asesinos y pordioseros. Alguien ha escrito sobre una vieja tabla de\n\
madera los barcos que atracan en el muelle de este puerto, que a decir verdad\n\
no son muchos. Si quieres salir de este horrible sitio ves al Oeste.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Ruido, barullo y follón, lo único que se escucha en estos puertos.\n");
 SetIntSmell("Hace un apestoso olor a pescado podrido.\n");

 AddExit("oeste","torre5");
 AddShip(SOTHKORN("sothkorn"));

 SetLocate("Glucksfall");
}
