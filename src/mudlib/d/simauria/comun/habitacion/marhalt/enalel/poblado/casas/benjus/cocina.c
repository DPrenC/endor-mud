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
    SetIntLong("Estás en una pequeña cocina donde todos los muebles son de "
    "madera, salvo el gran fogón. El salón está hacia el oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");

    AddDetail(({"fogon","fogón"}),"Es un gran fogón hecho de oscura piedra.\n");
    AddDetail(({"mueble","muebles","utensilio","utensilios"}),"Los muebles y "
    "utensilios de la cocina están hechos con una madera clara un tanto extraña.\n");

    AddExit("oeste",ENALHAB"poblado/casas/benjus/salon");
    AddDoor("oeste", "la puerta del salón",
    "La puerta para salir de la cocina al salón.\n",
    ({"puerta", "puerta del salon", "puerta del salón", "puerta del oeste"}));
}
