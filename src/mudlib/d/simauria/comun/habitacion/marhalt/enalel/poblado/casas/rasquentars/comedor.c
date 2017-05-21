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
    SetIntShort("el comedor");
    SetIntLong("Estás en un enorme comedor adornado con pomposos y recargados "
    "muebles. Las dimensiones de esta habitación son descomunales. Al oeste, "
    "una puerta comunica con la cocina. El salón de visitas está al norte "
    "mientras que al sur está el salón de entrada. Al este hay una pequeña "
    "puerta negra.\n");
    SetIntSmell("Del oeste parece venir un dulce aroma a comida.\n");

    AddExit("norte",ENALHAB"poblado/casas/rasquentars/salon_visitas");
    AddExit("este",ENALHAB"poblado/casas/rasquentars/despacho_anciano");
    AddExit("sur",ENALHAB"poblado/casas/rasquentars/salon_entrada");
    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/cocina");
    AddDoor("este", "una puerta oscura",
    "Una puerta oscura para entrar a un despacho.\n",
    ({"puerta", "puerta de un despacho", "puerta del este", "puerta del despacho"}));
    AddDoor("sur", "la puerta del salón de entrada",
    "La puerta para salir al salón de entrada de la vivienda.\n",
    ({"puerta", "puerta del salón de entrada", "puerta del salon de entrada",
        "puerta del sur"}));
    AddDoor("oeste", "la puerta de la cocina",
    "Una puerta normal para entrar a la cocina.\n",
    ({"puerta", "puerta de la cocina", "puerta del oeste"}));
}
