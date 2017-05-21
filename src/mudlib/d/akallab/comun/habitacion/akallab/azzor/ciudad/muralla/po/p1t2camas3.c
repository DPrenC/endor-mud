/*
DESCRIPCION : literas junto a un muro
FICHERO     : p1t2camas3.c
MODIFICACION: 10-03-00 [Angor@Simauria] Creacion
              01-09-01 [Angor@Simauria] Modificacion
*/

#include "path.h"
#include AK_MACRO
#include "/d/akallab/std/ciudad/puerta_ciudad.h"
#include "puerta.h"
inherit "/d/akallab/std/ciudad/puerta";

create()
{
	torre=DIR_TORRE_2;
	tipo=PC_PLANTA_1_TORRE_LITERAS;
	::create();
	AddExit(DIR_CIUDAD_TORRE_2,AZ_MURALLA_PO("p1t2armario1"));
    AddExit(DIR_CIUDAD_TORRE_1,AZ_MURALLA_PO("p1t2armario2"));
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p1t2centro2"));
}
