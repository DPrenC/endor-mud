/*
DESCRIPCION : centro del almacen de la torre
FICHERO     : p0t1centro2.c
MODIFICACION: 15-09-01 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include "/d/akallab/std/ciudad/puerta_ciudad.h"
#include "puerta.h"
inherit "/d/akallab/std/ciudad/puerta";

create()
{
	tipo=PC_PLANTA_0_CENTRO_1;
	::create();
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p0t1centro1"));
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p0t1lenya1"));
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p0t1lenya1"));	
	AddExit(DIR_TORRE_1,AZ_MURALLA_PO("p0t1cajas2"));
}
