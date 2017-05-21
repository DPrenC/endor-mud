/* camino03
   Camino hacia el Gremio de Psi�nicos
   Creaci�n: [n] Nemesis, 10-Abr-2001 23:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("sobre");
SetIntShort("un gran puente de piedra");
SetIntLong(
"Te encuentras frente a un majestuoso puente de piedra que da acceso a\
 un extra�o edificio situado sobre un pico de la monta�a. Aunque es muy\
 antiguo, sigue siendo sobrecogedor.\n");
SetIndoors(0);

AddDetail(({"puente"}),
"Es un poderoso puente de piedra que salva el abismo que hay entre el lugar "
"donde te encuentras y el edificio que ves en lontananza.\n");
AddDetail(({"edificio"}),
"No se distingue demasiado bien desde aqu�, pero parece magn�fico.\n");

AddExit("este","camino04");
AddExit("oeste","./camino02");

}