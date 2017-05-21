/* camino04
   Camino hacia el Gremio de Psi�nicos
   Creaci�n: [n] Nemesis, 10-Abr-2001 23:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un antiguo camino empedrado");
SetIntLong(
"Est�s en un camino empedrado que cruza las monta�as de este a oeste.\
 Las �nicas salidas posibles son proseguir el ascenso hacia el oeste o\
 descender hacia el este.\n");
SetIndoors(0);

AddDetail(({"camino"}),
"Est� bastante deteriorado, apenas puedes seguirlo.\n");

AddExit("este","camino05");
AddExit("oeste","./camino03");

}

