/*
DESCRIPCION : escalera exterior de la torre
FICHERO     : escalera03.c
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
	torre="norte";
	subir="sur";
	bajar="norte";
	tipo=PC_ESCALERA_PLANTA_0_1;
	::create();
	AddExit(DIR_TORRE_1,AZ_MURALLA_PO("escalera01"));
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("escalera05"));
}
