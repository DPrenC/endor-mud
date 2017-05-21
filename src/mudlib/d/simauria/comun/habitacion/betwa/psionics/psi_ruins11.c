/* psi_ruins11.c
   Escaleras del primer piso (ala norte)
   Creaci�n: [n] Nemesis, 19-Abr-2001 01:33:41 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un pasillo del primer piso");
SetIntLong(
"Te encuentras en un estrecho pasillo al final del cual hay unas escaleras\
 que conducen al piso de abajo. Al sur hay una vieja puerta corredera, que\
 parece dar acceso a una sala grande que podr�a ser una biblioteca.\n\
Unas escaleras conducen al piso de abajo.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"escaleras"}),
"Unas s�lidas escaleras de piedra que parecen conducir al piso de abajo.\n");
AddDetail(({"puerta","puerta corredera","vieja puerta","vieja puerta corredera"}),
"Est� abierta, y parece que lleva as� mucho tiempo. A trav�s de ella ves una "
"gran sala.\n");
AddDetail(({"sala"}),
"Una enorme sala que podr�a ser una biblioteca.\n");

AddExit("sur","./psi_ruins13");
AddExit("abajo","./psi_ruins08");

}

