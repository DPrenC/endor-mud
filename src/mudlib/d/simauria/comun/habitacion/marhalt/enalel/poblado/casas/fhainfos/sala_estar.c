/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Fhainfos");
    SetIntShort("la sala de estar");
    SetIntLong("Est�s en una peque�a sala de estar para uso y disfrute privado "
    "de los miembros de la familia. Unos c�modos sof�s y una mesita son el �nico "
    "moviliario de la salita. Al norte se encuentra el pasillo y al este una puerta "
    "comunica con la biblioteca de la familia.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"sofa","sof�","sofas","sof�s"}),"Son unos sof�s de piel muy c�modos.\n");
    AddDetail(({"mesa","mesita","mesilla"}),"Es una mesita de madera muy clara y elegante.\n");
    AddExit("norte",ENALHAB"poblado/casas/fhainfos/pasillo3");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/biblioteca");
    AddDoor("este", "la puerta de la biblioteca",
    "Una puerta de madera para pasar a la biblioteca.\n",
    ({"puerta", "puerta de la biblioteca", "puerta del este"}));
    AddDoor("norte", "la puerta del pasillo",
    "La puerta para salir de la estancia al pasillo.\n",
    ({"puerta", "puerta del pasillo", "puerta del norte"}));
}
