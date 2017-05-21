/*
DESCRIPCION : puerta de la sala del 1er nivel de la torre
FICHERO     : p1t2puerta.c
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
	salida=DIR_TORRE_1;
	tipo=PC_PLANTA_1_TORRE_PUERTA;
	::create();
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p1t2centro1"));
	AddExit(DIR_CIUDAD,AZ_MURALLA_PO("p1t2camas1"));	
	AddExit(DIR_TORRE_1,AZ_MURALLA_PO("p1agujero"));
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1t2armario2"));
}
