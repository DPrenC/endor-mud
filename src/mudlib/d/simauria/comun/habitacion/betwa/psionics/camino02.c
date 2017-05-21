/* camino02
   Camino hacia el Gremio de Psiónicos
   Creación: [n] Nemesis, 10-Abr-2001 23:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("sobre");
SetIntShort("un majestuoso puente");
SetIntLong(
"Estás sobre un puente de piedra que salva un ancho abismo. Es una obra\
 majestuosa, aunque el tiempo ha dejado su huella y puedes ver cóm algunas\
 de las estatuas que lo decoraban han sido derribadas o deterioradas hasta\
 dejarlas irreconocibles.\n");
SetIndoors(0);

AddDetail(({"puente"}),
"Es un poderoso puente de piedra que salva el abismo que hay entre el lugar "
"donde te encuentras y el edificio que ves en lontananza.\n");
AddDetail(({"edificio"}),
"Parece que es tan antiguo como el puente. Y también parece estar abandonado.\n");
AddDetail(({"abismo"}),
"Estás prácticamente en la cima de la montaña. No es el mejor lugar para "
"tropezar y caer.\n");
AddDetail(({"abajo"}),"¡No mires abajo!\n");
AddDetail(({"estatuas"}),
"Parecen representar figuras humanas, tal vez de reyes, o magos, o guerreros, "
"el tiempo no les ha hecho ningún bien.\n");

AddExit("este","camino03");
AddExit("oeste","./camino01");

}
