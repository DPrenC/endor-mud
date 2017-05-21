/* psi_ruins01.c
   Entrada del Gremio de Psiónicos
   Creación: [n] Nemesis, 11-Abr-2001 01:12:50 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("el patio de entrada al Gremio de Psiónicos");
SetIntLong(
"Te encuentras en lo que una vez fue el patio de entrada al Gremio de\
 Psiónicos. Sobre tu cabeza puedes ver el cielo e incluso algunas paredes\
 están derruídas. Te sientes triste al ver toda esta devastación.\n\
Hay salas al norte, al sur y al oeste. La salida está al este.\n");
SetIndoors(1);

AddDetail(({"paredes"}),
"A pesar de ser sólidas, muchas se han venido abajo. En algunas ves restos "
"de tapices.\n");
AddDetail(({"edificio","ruinas","gremio","gremio de psiónicos","gremio de psionicos"}),
"Ciertamente lleva mucho tiempo abandonado. No hay nada aparte de ruinas.\n");
AddDetail(({"tapices","restos de tapices"}),
"No hay nada que ver en ellos. Algunos fueron pasto de las llamas hace mucho, "
"mientras, que otros simplemente se desintegraron con los años.\n");
AddDetail(({"cielo","techo"}),
"El techo parece haberse derrumbado.\n");

AddExit("este","camino01");
AddExit("oeste","./psi_ruins02");
AddExit("norte","./psi_ruins08");
AddExit("sur","./psi_ruins07");


}
