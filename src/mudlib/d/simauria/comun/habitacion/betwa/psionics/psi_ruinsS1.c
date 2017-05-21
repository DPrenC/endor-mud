/* psi_ruinsS1.c
   S�tanos del Gremio
   Creaci�n: [n] Nemesis, 19-Abr-2001 01:05:47 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un oscuro subterr�neo");
SetIntLong(
"Te encuentras en un oscuro subterr�neo bastante h�medo.\
 Parece que esto fueron los s�tanos del gremio, ya que la habitaci�n est�\
 llena de trastos y cachivaches.\n\
Unas desvencijadas escaleras conducen a un trampilla abierta en el techo, \
mientras que un estrecho pasillo se adentra en las sombras hacia el oeste.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"trampilla","reja"}),
"Sin duda debe conducir al piso de arriba.\n");
AddDetail(({"escaleras"}),
"Unas carcomidas escaleras de madera son la �nica manera de llegar a la "
"trampilla.\n");
AddDetail(({"cachivaches","trastos"}),
"Casi todos est�n rotos, oxidados o ambas cosas. No hay nada de utilidad aqu� "
);

AddExit("oeste","psi_ruinsS2");
AddExit("arriba","./psi_ruins02");
HideExit("abajo");

}

