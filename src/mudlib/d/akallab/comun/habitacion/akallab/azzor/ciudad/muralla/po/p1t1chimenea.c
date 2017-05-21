/*
DESCRIPCION : chimena de la sala
FICHERO     : p1t1chimenea.c
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
	tipo=PC_PLANTA_1_TORRE_CHIMENEA;
	::create();
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1t1camas2"));
}
