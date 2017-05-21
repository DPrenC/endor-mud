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
    SetIntLong("Est�s en una c�moda estancia que sirve de despacho para el "
    "anciano de la familia. La decoraci�n es muy recargada y los tonos oscuros "
    "crean cierta presi�n en el ambiente. Una gran mesa preside la estancia y, "
    "a su alrededor, varios sillones invitan a la reuni�n. La puerta de salida "
    "est� al este.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("mesa","Es una mesa enorme de madera oscura. Encima, hay diversos documentos.\n");
    AddDetail(({"sillon","sill�n","sillones"}),"Son unos exquisitos sillones muy c�modos.\n");
    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/comedor");
    AddDoor("oeste", "una puerta oscura",
    "Una puerta oscura de madera.\n",
    ({"puerta", "puerta del comedor", "puerta del oeste"}));
}