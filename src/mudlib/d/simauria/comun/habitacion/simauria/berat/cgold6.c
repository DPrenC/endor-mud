/*
DESCRIPCION  : calle golduin
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cgold6.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
                        [Nem] Revisado y Corregido
						[Mal]
--------------------------------------------------------------------------------
*/
#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Berat");
SetIntShort("la calle Golduin");
SetIntLong(W("Te encuentras en la parte nordeste de la ciudad de"
" Berat, en la calle Golduin. Aqu� se una al sur con la calle Koldar"
" y continua al oeste hacia la calle principal. Montones de ramas y"
" arbustos ca�dos rodean el camino, se�al de que el camino esta en"
" expansi�n todav�a.\n"));
SetIndoors(0);
SetIntSmell("Huele a comida reci�n hecha.\n");
AddDetail(({"camino","calle"}),W("Es la calle m�s nueva del pueblo, "
"las piedras que lo forman no est�n casi desgastadas.\n"));
AddDetail(({"casas","casa"}),W("Parecen unas casas bastante altas "
"pero muy sencillas.\n"));
AddDetail(({"piedras"}),"Son planas para que las ruedas de los carros no se rompan.\n");
AddDetail(({"arbustos","ramas"}),"Las ramas y hojas impiden el paso.\n");
AddExit("sur","/d/simauria/comun/habitacion/simauria/berat/ckol1");
AddExit("oeste","/d/simauria/comun/habitacion/simauria/berat/cgold5");
}

