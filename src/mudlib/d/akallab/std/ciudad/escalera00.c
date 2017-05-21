/*
DESCRIPCION : escalera exterior de la torre
FICHERO     : po_escalera00.c
MODIFICACION: 25-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include "puerta_ciudad.h"
#include "puerta.h"
inherit "/d/akallab/std/ciudad/puerta";

create()
{
    //::initVarsPuerta();
 	torre="sur";
	subir="norte";
	tipo=PC_ESCALERA_PLANTA_BAJA;

	::create();
	
	//AddExit("este",AZ_CIUDAD("calle??"));
	//AddExit(DIR_TORRE_1,AZ_MURALLA_PO("escalera02");
}
