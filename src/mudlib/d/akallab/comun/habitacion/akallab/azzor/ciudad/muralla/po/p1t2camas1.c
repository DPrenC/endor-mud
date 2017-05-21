/*
DESCRIPCION : literas junto a un muro
FICHERO     : p1t2camas1.c
MODIFICACION: 10-03-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include "/d/akallab/std/ciudad/puerta_ciudad.h"
#include "puerta.h"
inherit "/d/akallab/std/ciudad/puerta";

create()
{
 	torre=DIR_TORRE_2;
	tipo=PC_PLANTA_1_TORRE_LITERAS;
	::create();
	AddExit(DIR_TORRE_2,AZ_MURALLA_PO("p1t2escalera"));
	AddExit(DIR_FUERA,AZ_MURALLA_PO("p1t2puerta"));
}
