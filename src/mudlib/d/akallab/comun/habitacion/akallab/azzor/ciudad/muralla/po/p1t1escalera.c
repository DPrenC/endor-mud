/*
DESCRIPCION : principio de la escalera al piso 2
FICHERO     : p1t1escalera.c
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
	subir=DIR_TORRE_1;
	tipo=PC_PLANTA_1_TORRE_ESCALERA;
	::create();
	//AddExit(DIR_TORRE_1,AZ_MURALLA_PO("p1t1camas3"));
    AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p1t1camas1"));
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1t1centro1"));
}
