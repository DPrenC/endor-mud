/* Coded by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria para implementar a Nightfall(tm).
   Ultima modificacion: 10 Oct, 1997.
 */
#include "path.h"
inherit KHA_ROOM;

create() {
   ::create();

SetIntShort("la tercera planta del Torreón");
SetIntLong(
"Estas en la tercera planta del torreon del Castillo Kha-annu. Las escaleras "
"continuan hacia arriba y hacia abajo.\n");

SetIntBright(90);

SetIndoors(1);

AddExit("arriba", PISO1+"torreon3");
AddExit("abajo", PISO1+"torreon1");

AddDetail(({"vela","velas","antorcha","antorchas"}),
"Unas grandes antorchas sujetas en las paredes iluminan el torreon.\n");
AddDetail(({"pared","paredes"}),
"Las paredes son antiguas, pero solidas y resistentes.\n");
AddDetail(({"escalera","escaleras"}),
"Unas estrechas escaleras de caracol recorren de arriba hacia abajo este "
"enorme torreon.\n");
}