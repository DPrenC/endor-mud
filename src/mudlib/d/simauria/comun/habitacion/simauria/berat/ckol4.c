/*
DESCRIPCION  : calle koldar
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ckol4.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
						[Mal]
--------------------------------------------------------------------------------
*/
#include "path.h"

inherit SIM_ROOM;
#include <rooms.h>
create() {
::create();
SetLocate("Berat");
SetIntShort("la calle Koldar");
SetIntLong(W("Estás en la parte sur de la calle Koldar, la calle "
"continua al norte y se une mediante una callejuela, a la calle "
"principal hacia el oeste, el riachuelo que bordea la calle Koldar "
"va desde el este al sur de la calle acompañándola en su curva.\n"));
SetIndoors(0);
SetIntNoise("Escuchas el murmullo del riachuelo.\n");
AddDetail(({"camino","calle"}),W("Es la calle más bella del pueblo "
"y también la más tranquila y solitaria.\n"));
AddDetail(({"riachuelo"}),W("Es uno de los riachuelos que forman el "
"delta en el que se encuentra Berat. La calle coincide con el recodo "
"del riachuelo.\n"));
AddExit("norte","/d/simauria/comun/habitacion/simauria/berat/ckol3");
AddExit("oeste","/d/simauria/comun/habitacion/simauria/berat/calle3");
}

