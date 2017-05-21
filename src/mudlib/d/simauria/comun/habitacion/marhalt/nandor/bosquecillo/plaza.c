/*
DESCRIPCION  : uan plaza
FICHERO      : plaza.c
CREACION     : 03-12-01 [Bomber] 
*/

#include "path.h"

inherit SIM_ROOM;

create()
{
	::create();

	SetIntShort("una pequeña plaza");
	SetIntLong(W("Estas en una pequeña plaza de lo que parece ser una aldea "
                   "perdida en medio del bosque. Una ridicula fuente adorna un "
                   "suelo sucio mas lleno de humus que de adoquines. Hacia el este, "
                   "sin embargo, un edificio destaca sobre los demas (sobre los otros 2); "
                   "es el AYUNTAMIENTO (¿que demonios hara un ayuntamiento en medio de una "
                   "minialdea?). Al sur puedes ver una pequeña y mas bien mal hecha tienda, "
                   "y al norte lo que parece ser una posada.\n"));
	
	SetLocate("???"); 
	SetIndoors(0);
	SetIntNoise("Oyes el murmullo de la gente en la plaza .\n");
	SetIntSmell("Huele a bosque.\n");
	//AddItem();//METER AQUI UNA FUENTE, O LO QUE SEA
	AddExit("norte","posada");
	AddExit("sur","tienda");
	AddExit("este","ayuntamiento");
	AddExit("oeste","senda8");
}


