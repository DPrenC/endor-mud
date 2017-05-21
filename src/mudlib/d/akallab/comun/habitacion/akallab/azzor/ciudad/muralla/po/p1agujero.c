/*
DESCRIPCION : centro del primer nivel de la torre junto al agujero
FICHERO     : p1agujero.c
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
	tipo=PC_PLANTA_1_CENTRO_AGUJERO;
	::create();
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1muro"));
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p1balcon"));
	AddExit(DIR_TORRE_1,AZ_MURALLA_PO("p1t1puerta"));
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p1t2puerta"));
}
