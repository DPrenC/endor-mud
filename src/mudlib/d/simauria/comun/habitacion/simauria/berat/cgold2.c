/*
DESCRIPCION  : calle golduin
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cgold2.c
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
SetIntLong(W("Est�s en la calle Golduin, todav�a en construcci�n, "
"puedes ver piedras y tierra con las que se esta construyendo. "
"Las piedras que forman el camino apenas est�n desgastadas, y todav�a "
"se mueven. La calle continua al este y al oeste, quedando cortada al "
"norte por una densa maleza. Parece que la construcci�n de nuevos caminos "
"es fruto de la r�pida expansi�n del pueblo. Al sur puedes ver las casas "
"del pueblo.\n"));
SetIndoors(0);
SetIntNoise("Escuchas el bullicio t�pico de un pueblo como Berat.\n");
SetIntSmell("Huele a hierba.\n");
AddDetail(({"camino","calle"}),W("Es la calle m�s nueva del pueblo, "
"las piedras que lo forman no est�n casi desgastadas.\n"));
AddDetail(({"casas","casa"}),W("Parecen unas casas bastante altas "
"pero muy sencillas.\n"));
AddDetail(({"piedras","tierra"}),W("Parecen piedras planas y tierra "
"para la construcci�n de caminos.\n"));
AddDetail(({"maleza"}),"Las ramas y hojas impiden el paso.\n");
AddExit("este","/d/simauria/comun/habitacion/simauria/berat/cgold3");
AddExit("oeste","/d/simauria/comun/habitacion/simauria/berat/cgold1");
AddItem("/d/simauria/comun/pnj/simauria/berat/guardia",REFRESH_DESTRUCT,1);
}

