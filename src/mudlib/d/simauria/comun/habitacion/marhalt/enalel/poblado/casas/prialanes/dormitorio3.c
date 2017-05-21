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
    SetIntLong("Est�s en uno de los dormitorios de la familia Prialane. En este "
    "dormitorio parece que no duerme nadie ya que no hay muebles de ning�n tipo. "
    "La salida est� hacia el este.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");

    AddExit("este",ENALHAB"poblado/casas/prialanes/pasillo");
    AddDoor("este", "la puerta del pasillo",
    "La puerta para salir de la habitaci�n.\n",
    ({"puerta", "puerta de salida", "puerta del pasillo", "puerta del este"}));
}
