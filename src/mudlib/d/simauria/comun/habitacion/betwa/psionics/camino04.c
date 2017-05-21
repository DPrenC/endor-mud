/* camino04
   Camino hacia el Gremio de Psiónicos
   Creación: [n] Nemesis, 10-Abr-2001 23:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un antiguo camino empedrado");
SetIntLong(
"Estás en un camino empedrado que cruza las montañas de este a oeste.\
 Las únicas salidas posibles son proseguir el ascenso hacia el oeste o\
 descender hacia el este.\n");
SetIndoors(0);

AddDetail(({"camino"}),
"Está bastante deteriorado, apenas puedes seguirlo.\n");

AddExit("este","camino05");
AddExit("oeste","./camino03");

}

