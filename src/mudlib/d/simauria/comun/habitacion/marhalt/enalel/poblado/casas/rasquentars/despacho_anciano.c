/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("un despacho");
    SetIntLong("Estás en una cómoda estancia que sirve de despacho para el "
    "anciano de la familia. La decoración es muy recargada y los tonos oscuros "
    "crean cierta presión en el ambiente. Una gran mesa preside la estancia y, "
    "a su alrededor, varios sillones invitan a la reunión. La puerta de salida "
    "está al este.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("mesa","Es una mesa enorme de madera oscura. Encima, hay diversos documentos.\n");
    AddDetail(({"sillon","sillón","sillones"}),"Son unos exquisitos sillones muy cómodos.\n");
    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/comedor");
    AddDoor("oeste", "una puerta oscura",
    "Una puerta oscura de madera.\n",
    ({"puerta", "puerta del comedor", "puerta del oeste"}));
}