/*
DESCRIPCION : escalera exterior de la torre
FICHERO     : escalera04.c
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
	torre="sur";
	subir="norte";
	bajar="sur";
	tipo=PC_ESCALERA_PLANTA_1;
	::create();
	AddExit(DIR_FUERA_TORRE_1,AZ_MURALLA_PO("p1balcon"));
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("escalera02"));
}