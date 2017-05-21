/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, para implemental a Nightfall(tm).
   Ultima modificacion: 9 Oct, 1997.
 */
#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("la bajada a las mazmorras");
SetIntLong(
"Te encuentras en unas escaleras que bajan hacia las mazmorras. Hay una puerta "
"al este y otra al oeste. La puerta este lleva a la cocina y detras de la puerta "
"oeste esta el basurero. Al norte puedes ver el puesto de vigilancia.\n");

SetIntBright(90);

AddExit("norte", PISO1+"vigila");
AddExit("este", PISO1+"cocina");
AddExit("oeste", PISO1+"basura");
AddExit("abajo",DUNGEONS+"1entrada");

AddDetail(({"puesto","puesto de vigilancia","puesto vigilancia",
                "vigilancia"}),
"El puesto de vigilancia no tiene nada en especial.\n");
AddDetail(({"mazmorra","mazmorras"}),
"Unas sucias escaleras bajan a las mazmorras del castillo Kha-annu.\n");
AddDetail(({"escaleras","escalera"}),
"Solo son unas sucias escaleras que bajan a laz mazmorras.\n");
AddDetail("cocina",
"Hay una gran cocina hacia el este. Es donde el cocinero hace la comida a los "
"prisioneros.\n");
SetIntSmell(
"Un hedor horrendo viene del oeste... Parece ser del basurero del castillo.\n");
}