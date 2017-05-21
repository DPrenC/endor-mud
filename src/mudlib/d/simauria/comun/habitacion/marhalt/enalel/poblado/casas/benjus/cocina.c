/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Benjus");
    SetIntShort("la cocina");
    SetIntLong("Est�s en una peque�a cocina donde todos los muebles son de "
    "madera, salvo el gran fog�n. El sal�n est� hacia el oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");

    AddDetail(({"fogon","fog�n"}),"Es un gran fog�n hecho de oscura piedra.\n");
    AddDetail(({"mueble","muebles","utensilio","utensilios"}),"Los muebles y "
    "utensilios de la cocina est�n hechos con una madera clara un tanto extra�a.\n");

    AddExit("oeste",ENALHAB"poblado/casas/benjus/salon");
    AddDoor("oeste", "la puerta del sal�n",
    "La puerta para salir de la cocina al sal�n.\n",
    ({"puerta", "puerta del salon", "puerta del sal�n", "puerta del oeste"}));
}
