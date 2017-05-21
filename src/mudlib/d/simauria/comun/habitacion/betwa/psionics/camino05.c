/* camino05
   Camino hacia el Gremio de Psi�nicos
   Creaci�n: [n] Nemesis, 10-Abr-2001 23:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un cruce de caminos");
SetIntLong(
"Has llegado a un cruce. El camino principal se extiende de este a oeste,\
 pero dos ramales m�s peque�os parten hacia el norte y el suroeste. En el\
 centro del cruce hay un poste indicador.\n");
SetIndoors(0);

AddReadMsg(({"signos","inscripci�n","extra�os signos","extranyos signos"}),
"Es in�til, los signos est�n demasiado deteriorados. S�lo la flecha del oeste "
"es legible en parte: 'G   O  E  SI  I   S'.\n");
AddDetail(({"camino"}),
"Est� tremendamente deteriorado, apenas puedes seguirlo.\n");
AddDetail(({"poste","poste indicador","indicador"}),
"Tiene unos extra�os signos escritos.\n");
AddDetail(({"signos","extra�os signos","extranyos signos","signos escritos",
	    "inscripci�n","inscripcion"}),
"La inscripci�n est� tan deteriorada que apenas es legible, aunque podr�as "
"intentar leer los signos...\n");
AddDetail(({"cruce"}),SF(QueryIntLong));

AddExit("norte","cruce_nor");
AddExit("sur","cruce_sur");
AddExit("este","camino06");
AddExit("oeste","./camino04");

}

