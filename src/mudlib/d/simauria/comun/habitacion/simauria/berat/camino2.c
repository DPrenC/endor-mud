/*
DESCRIPCION  : camino
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/camino2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
                        [Nem] Revisado y Corregido
--------------------------------------------------------------------------------
*/
#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Berat");
SetIntShort("el camino de Berat");
SetIntLong(W("Estás en la entrada de Berat, al sur comienza la calle"
" principal de la ciudad y al norte continua el camino, hacia Simauria.\n"));
SetIndoors(0);
SetIntNoise("Escuchas el canto de los pájaros.\n");
SetIntSmell("Huele a hierba fresca.\n");
AddDetail(({"pajaro","pajaros","pájaro","pájaros"}),"No consigues verlos entre los árboles.\n");
AddDetail(({"camino"}),W("Es un camino de tierra con marcas de ruedas de"
" carromato, y pisadas de caballos.\n"));
AddDetail(({"arboles","arbol"}),W("Hay árboles en los laterales del"
" camino.\n"));
AddExit("norte","/d/simauria/comun/habitacion/simauria/berat/puente1");
AddExit("sur","/d/simauria/comun/habitacion/simauria/berat/cprin1");
}

