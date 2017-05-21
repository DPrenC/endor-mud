/* psi_ruins07.c
   Escaleras del sur
   Creación: [n] Nemesis, 19-Abr-2001 01:11:34 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un pasillo sombrío");
SetIntLong(
"Te encuentras en un estrecho pasillo al final del cual hay unas escaleras\
 que conducen al piso de arriba. No hay mucho que ver, salvo algunas manchas\
 en la pared.\n\
Hay una puerta que conduce a la entrada al norte.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"escaleras"}),
"Parecen conducir al piso de arriba. Por otro lado, quién sabe, igual no "
"conducen a ninguna parte...\n");
AddDetail(({"manchas"}),
"Puedes ver manchas de humedad, de barro, de humo, huellas de pies,... esto "
"parece el Catálogo Universal de Manchas.\n");

AddExit("norte","./psi_ruins01");
AddExit("arriba","./psi_ruins12");

}

