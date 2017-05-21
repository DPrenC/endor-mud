/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin1.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
--------------------------------------------------------------------------------
*/
#include "path.h"
inherit SIM_ROOM;
create() {
::create();
SetLocate("Berat");
SetIntShort("un cruce de Berat");
SetIntLong(W("Estás en la calle principal de Berat, en este punto"
" se cruza con la calle Golduin, que va de este a oeste. Puedes ver"
" las casas que bordean la calle.\n"));
SetIndoors(0);
SetIntNoise("Escuchas el bullicio típico de un pueblo como Berat.\n");
AddDetail(({"camino","calle"}),W("Es la calle más grande de la ciudad"
" y las piedras que lo forman estan muy desgastadas.\n"));
AddDetail(({"casas","casa"}),"Parecen unas casas bastante altas pero muy sencillas.\n");
AddDetail(({"piedras"}),"Parecen cantos rodados, muy desgastados.\n");
AddExit("norte","/d/simauria/comun/habitacion/simauria/berat/camino2");
AddExit("sur","/d/simauria/comun/habitacion/simauria/berat/cprin2");
AddExit("este","/d/simauria/comun/habitacion/simauria/berat/cgold4");
AddExit("oeste","/d/simauria/comun/habitacion/simauria/berat/cgold3");
}

