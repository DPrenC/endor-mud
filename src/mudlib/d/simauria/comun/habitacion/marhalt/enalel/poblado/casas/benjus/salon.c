/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"
#include <sounds.h>
inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(50);
    SetLocate("Casa Benjus");
    SetIntShort("el gran salón");
    SetIntLong("Estás en un enorme y rústico salón, cuyos muros y pilares son "
    "de robusta madera. Una gran mesa de madera preside la estancia y una chimenea "
    "al fondo calienta siempre este salón. \nAl este se encuentra la cocina de la "
    "casa y al oeste se encuentra un pasillo. \n Al sur se puede salir de la casa.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"mesa","enorme mesa","mesa de madera"}),"Es una enorme mesa de "
    "madera tallada en un gran tronco de manzano.\n");
    AddDetail("chimenea","Es una enorme chimenea que siempre permanece "
    "encendida para calentar el lugar.\n La chimenea desprende un confortable "
    "calorcito que envuelve tu cuerpo.\n");
    SetSoundEnvironment(SND_AMBIENTES("chimenea"));
    AddExit("este",ENALHAB"poblado/casas/benjus/cocina");
    AddExit("oeste",ENALHAB"poblado/casas/benjus/pasillo1");
    AddExit("sur",ENALHAB"poblado/casas/benjus/hall");
    AddDoor("este", "la puerta de la cocina",
    "La puerta para entrar a la cocina.\n",
    ({"puerta", "puerta de la cocina", "puerta del este"}));
}
