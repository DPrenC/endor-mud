/*
DESCRIPCION : zona de cajas en el almacen de la torre
FICHERO     : p0t1cajas2.c
MODIFICACION: 15-09-01 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include "/d/akallab/std/ciudad/puerta_ciudad.h"
#include "puerta.h"
inherit "/d/akallab/std/ciudad/puerta";

create()
{
	tipo=PC_PLANTA_0_CAJAS;
	::create();
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p0t1centro2"));
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p0t1escalera"));	
	AddExit(DIR_FUERA_TORRE_2,AZ_MURALLA_PO("p0t1lenya2"));	
}
