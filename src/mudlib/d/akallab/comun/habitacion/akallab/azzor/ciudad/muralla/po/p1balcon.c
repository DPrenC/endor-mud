/*
DESCRIPCION : balconada del primer nivel de la torre
FICHERO     : p1balcon.c
MODIFICACION: 25-02-00 [Angor@Simauria] Creacion
              01-09-01 [Angor@Simauria] Modificacion
*/

#include "path.h"
#include AK_MACRO
#include "/d/akallab/std/ciudad/puerta_ciudad.h"
#include "puerta.h"
inherit "/d/akallab/std/ciudad/puerta";

create()
{
	tipo=PC_PLANTA_1_CENTRO_BALCON;
	::create();
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1agujero"));
	AddExit(DIR_CIUDAD_TORRE_1,AZ_MURALLA_PO("escalera05"));
	AddExit(DIR_CIUDAD_TORRE_2,AZ_MURALLA_PO("escalera04"));
}