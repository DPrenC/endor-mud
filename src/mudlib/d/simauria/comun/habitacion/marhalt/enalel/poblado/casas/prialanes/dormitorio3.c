/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Prialanes");
    SetIntShort("un dormitorio");
    SetIntLong("Estás en uno de los dormitorios de la familia Prialane. En este "
    "dormitorio parece que no duerme nadie ya que no hay muebles de ningún tipo. "
    "La salida está hacia el este.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");

    AddExit("este",ENALHAB"poblado/casas/prialanes/pasillo");
    AddDoor("este", "la puerta del pasillo",
    "La puerta para salir de la habitación.\n",
    ({"puerta", "puerta de salida", "puerta del pasillo", "puerta del este"}));
}
