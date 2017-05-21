/* psi_ruinsS2.c
   S�tanos del Gremio
   Creaci�n: [n] Nemesis, 19-Abr-2001 01:05:47 CEST
   Notas: Es casi seguro que aqu� habr� una piedrecilla.
          C�mo obtenerla, es otra historia.
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un oscuro subterr�neo");
SetIntLong(
"Te encuentras en un oscuro subterr�neo bastante h�medo.\
 La habitaci�n est� llena de trastos a cu�l m�s destrozado, haciendo que\
 el lugar parezca a�n m�s desolado.\n\
Un estrecho pasillo se adentra en las sombras hacia el este.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"cachivaches","trastos","objetos"}),
"Algunos viejos sacos rotos, varias cajas destrozadas y otros objetos "
"irreconocibles es todo lo que ves por aqu�. Nada que merezca la pena coger.\n");
AddDetail(({"cajas","cajas destrozadas"}),
"En su momento contuvieron algo, pero su contenido se desparram� hace mucho, "
"y ahora no podr�as decir cu�l de todos estos trastos estuvo dentro de cu�l "
"de las cajas.\n");
AddDetail(({"sacos","sacos rotos"}),
"Est�n vac�os. Puede que contuvieran alguna clase de semilla.\n");
AddDetail(({"objetos irreconocibles"}),
"Algunos parecen m�quinas y otros objetos decorativos, aunque la mayor�a son "
"simplemente chatarra.\n");

AddExit("este","psi_ruinsS1");
}

