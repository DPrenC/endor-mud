/*
DESCRIPCION  : calle golduin
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cgold5.c
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
SetIntLong(W("Estás en la calle Golduin, la calle esta aún en "
"construccion, faltan tantas piedras que impiden, el paso de carros y "
 "carretas, la calle continua al oeste y al este, y una barrera de "
"arbustos te impide ir al norte.\n"));
SetIndoors(0);
SetIntSmell("Huele a comida recién hecha.\n");
AddDetail(({"camino","calle"}),W("Es la calle mas nueva del pueblo, "
"las piedras que lo forman no estan casi desgastadas.\n"));
AddDetail(({"casas","casa"}),W("Parecen unas casas bastante altas "
"pero muy sencillas.\n"));
AddDetail(({"piedras"}),"Parecen piedras planas apenas desgastadas.\n");
AddDetail(({"arbustos"}),"Las ramas y hojas impiden el paso.\n");
AddExit("este","/d/simauria/comun/habitacion/simauria/berat/cgold6");
AddExit("oeste","/d/simauria/comun/habitacion/simauria/berat/cgold4");
}

