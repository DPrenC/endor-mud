/*
DESCRIPCION : centro del primer nivel de la torre junto al muro
FICHERO     : p1muro.c
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
	tipo=PC_PLANTA_1_CENTRO_MURO;
	::create();
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p1agujero"));
}
