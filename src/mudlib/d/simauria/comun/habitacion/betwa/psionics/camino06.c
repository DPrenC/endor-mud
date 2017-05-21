/* camino06
   Camino hacia el Gremio de Psi�nicos
   Creaci�n: [n] Nemesis, 10-Abr-2001 23:35:04 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un antiguo camino");
SetIntLong(
"Te encuentras en un antiguo camino que ascend�a a las monta�as. Por el\
 estado en que se encuentra actualmente, parece que no ha sido usado en a�os,\
 aunque todav�a son visibles algunas losas del antiguo firme. Gui�ndote por\
 ellas, ves que el camino prosigue su ascenso hacia el oeste, mientras que\
 hacia el este desciende hacia el valle.\n");
SetIndoors(0);

AddDetail(({"camino"}),
"Est� tremendamente deteriorado, apenas puedes seguirlo.\n");
AddDetail(({"losas"}),
"Son grandes losas de piedra que formaban el pavimento del camino. "
"A juzgar por su tama�o, este camino debi� ser importante en el pasado.\n");

AddExit("este","camino07");
AddExit("oeste","./camino05");

}

