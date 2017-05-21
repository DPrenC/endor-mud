/*
DESCRIPCION  : calle golduin
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cgold1.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
                        [Nem] Revisado y Corregido
--------------------------------------------------------------------------------
*/
#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Berat");
SetIntShort("la calle Golduin");
SetIntLong(W("Estás en la calle Golduin, que se extiende hacia "
"el este. Aquí la calle se une con la del mercado que va hacia el sur y al oeste y al norte la calle está cortada por la maleza.\n"));
SetIndoors(0);
SetIntNoise("Escuchas el bullicio típico de un pueblo como Berat.\n");
SetIntSmell("Huele a hierba.\n");
AddDetail(({"camino","calle"}),W("Es la calle más nueva del pueblo, "
"las piedras que lo forman no están apenas desgastadas.\n"));
AddDetail(({"maleza"}),"Las ramas y hojas impiden el paso.\n");
AddDetail(({"piedras","tierra"}),W("Parecen piedras planas y tierra "
"para la construcción de caminos.\n"));
AddExit("sur","/d/simauria/comun/habitacion/simauria/berat/cmerc1");
AddExit("este","/d/simauria/comun/habitacion/simauria/berat/cgold2");
}

