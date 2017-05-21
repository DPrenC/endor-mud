/*
DESCRIPCION : escalera exterior de la torre
FICHERO     : escalera01.c
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
	tipo=PC_ESCALERA_PLANTA_BAJA;
	::create();
	//AddExit("este",AZ_CIUDAD("calle??"));
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("escalera03"));
}
