/*
DESCRIPCION : puerta de la sala del 1er nivel de la torre
FICHERO     : p1t1puerta.c
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
	torre=DIR_TORRE_1;
	salida=DIR_TORRE_2;
	tipo=PC_PLANTA_1_TORRE_PUERTA;
	::create();
	AddExit(DIR_TORRE_1,AZ_MURALLA_PO("p1t1centro1"));
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p1t1camas1"));	
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p1agujero"));
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1t1armario2"));
}
