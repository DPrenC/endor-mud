/* psi_ruins04.c
   En un mirador.
   Creación: [n] Nemesis, 18-Abr-2001 21:58:24 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un bello jardín");
SetIntLong(
W("Te encuentras en un mirador, construído sobre una cornisa de la montaña.\
 Sólo una precaria barandilla te protege de una caída, aunque el suelo parece\
 sólido y sólo tienes que evitar acercarte demasiado al borde. Por otro lado,\
 la vista es magnífica.\n\
Puedes entrar en un bello jardín cubierto hacia el norte.\n" ));
SetIndoors(0);

AddDetail(({"jardín","jardin"}),
"Es un jardín cubierto con una cúpula de cristal. Te preguntas a quién se "
"le ocurriría semejante idea.\n");
AddDetail(({"vista","abajo"}),
"Desde esta altura puedes contemplar las cumbres y valles que rodean esta "
"montaña.\n");
AddDetail(({"valles"}),
"Hay bastantes fértiles valles situados entre las montañas.\n");
AddDetail(({"cumbres","montañas"}),
"Debe ser una de las montañas más altas de la cordillera. Casi todas las "
"otras están por debajo de ti.\n");
AddItem(OBJETO+"otro/edelweiss",REFRESH_REMOVE,1);

AddExit("norte","psi_ruins04");

}