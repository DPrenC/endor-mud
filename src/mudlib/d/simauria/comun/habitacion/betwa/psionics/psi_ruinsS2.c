/* psi_ruinsS2.c
   Sótanos del Gremio
   Creación: [n] Nemesis, 19-Abr-2001 01:05:47 CEST
   Notas: Es casi seguro que aquí habrá una piedrecilla.
          Cómo obtenerla, es otra historia.
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un oscuro subterráneo");
SetIntLong(
"Te encuentras en un oscuro subterráneo bastante húmedo.\
 La habitación está llena de trastos a cuál más destrozado, haciendo que\
 el lugar parezca aún más desolado.\n\
Un estrecho pasillo se adentra en las sombras hacia el este.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"cachivaches","trastos","objetos"}),
"Algunos viejos sacos rotos, varias cajas destrozadas y otros objetos "
"irreconocibles es todo lo que ves por aquí. Nada que merezca la pena coger.\n");
AddDetail(({"cajas","cajas destrozadas"}),
"En su momento contuvieron algo, pero su contenido se desparramó hace mucho, "
"y ahora no podrías decir cuál de todos estos trastos estuvo dentro de cuál "
"de las cajas.\n");
AddDetail(({"sacos","sacos rotos"}),
"Están vacíos. Puede que contuvieran alguna clase de semilla.\n");
AddDetail(({"objetos irreconocibles"}),
"Algunos parecen máquinas y otros objetos decorativos, aunque la mayoría son "
"simplemente chatarra.\n");

AddExit("este","psi_ruinsS1");
}

