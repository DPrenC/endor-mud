/*
DESCRIPCION : parte comun de la puerta de la ciudad
FICHERO     : puerta.c
MODIFICACION: 25-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include "puerta_ciudad.h"
#include "puerta.h"

inherit PUERTA_CIUDAD;

public void initVarsPuerta()
{
	ciudad=NOMBRE_CIUDAD;
	entrada=NOMBRE_ENTRADA;
    dir_ciudad=DIR_CIUDAD;
    dir_fuera=DIR_FUERA;
	dir_torre1=DIR_TORRE_1;
	dir_torre2=DIR_TORRE_2;
	return;
}

create()
{
    initVarsPuerta();
	::create();
	SetIntNoise("No oyes nada en especial.\n");
	SetIntSmell("No huele a nada en especial.\n");
	SetLocate("ciudad de "+NOMBRE_CIUDAD);
}
