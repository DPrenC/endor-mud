/* camino05
   Camino hacia el Gremio de Psiónicos
   Creación: [n] Nemesis, 10-Abr-2001 23:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un cruce de caminos");
SetIntLong(
"Has llegado a un cruce. El camino principal se extiende de este a oeste,\
 pero dos ramales más pequeños parten hacia el norte y el suroeste. En el\
 centro del cruce hay un poste indicador.\n");
SetIndoors(0);

AddReadMsg(({"signos","inscripción","extraños signos","extranyos signos"}),
"Es inútil, los signos están demasiado deteriorados. Sólo la flecha del oeste "
"es legible en parte: 'G   O  E  SI  I   S'.\n");
AddDetail(({"camino"}),
"Está tremendamente deteriorado, apenas puedes seguirlo.\n");
AddDetail(({"poste","poste indicador","indicador"}),
"Tiene unos extraños signos escritos.\n");
AddDetail(({"signos","extraños signos","extranyos signos","signos escritos",
	    "inscripción","inscripcion"}),
"La inscripción está tan deteriorada que apenas es legible, aunque podrías "
"intentar leer los signos...\n");
AddDetail(({"cruce"}),SF(QueryIntLong));

AddExit("norte","cruce_nor");
AddExit("sur","cruce_sur");
AddExit("este","camino06");
AddExit("oeste","./camino04");

}

