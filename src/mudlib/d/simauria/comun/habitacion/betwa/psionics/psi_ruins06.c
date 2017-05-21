/* psi_ruins04.c
   En un mirador.
   Creaci�n: [n] Nemesis, 18-Abr-2001 21:58:24 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un bello jard�n");
SetIntLong(
W("Te encuentras en un mirador, constru�do sobre una cornisa de la monta�a.\
 S�lo una precaria barandilla te protege de una ca�da, aunque el suelo parece\
 s�lido y s�lo tienes que evitar acercarte demasiado al borde. Por otro lado,\
 la vista es magn�fica.\n\
Puedes entrar en un bello jard�n cubierto hacia el norte.\n" ));
SetIndoors(0);

AddDetail(({"jard�n","jardin"}),
"Es un jard�n cubierto con una c�pula de cristal. Te preguntas a qui�n se "
"le ocurrir�a semejante idea.\n");
AddDetail(({"vista","abajo"}),
"Desde esta altura puedes contemplar las cumbres y valles que rodean esta "
"monta�a.\n");
AddDetail(({"valles"}),
"Hay bastantes f�rtiles valles situados entre las monta�as.\n");
AddDetail(({"cumbres","monta�as"}),
"Debe ser una de las monta�as m�s altas de la cordillera. Casi todas las "
"otras est�n por debajo de ti.\n");
AddItem(OBJETO+"otro/edelweiss",REFRESH_REMOVE,1);

AddExit("norte","psi_ruins04");

}