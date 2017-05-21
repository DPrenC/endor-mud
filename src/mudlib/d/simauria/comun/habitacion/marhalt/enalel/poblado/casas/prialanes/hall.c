/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <materials.h>
#include <properties.h>
inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("el hall de la mansión");
    SetIntLong("Estás en el hall de la entrada de la casa de la adinerada "
    "familia Prialane. El edificio es una extraña construcción formada por "
    "distintos módulos y anexos construidos con distintos estilos arquitectónicos. "
    "Parece que cada generación ha aportado su toque personal a la vivienda. La "
    "entrada a lo que parece un jardín está hacia el sudeste y al suroeste está "
    "el resto de la mansión.\n Al norte está la salida a la calle del comercio.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");

    AddExit("norte",ENALHAB"poblado/calles/calle05");
    AddExit("sudeste",ENALHAB"poblado/casas/prialanes/jardin1");
    AddExit("suroeste",ENALHAB"poblado/casas/prialanes/salon");
    AddDoor("norte", "la puerta de la calle",
    "Es la puerta de salida de la casa.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del norte"}));
    AddDoor("sudeste", "la puerta del jardín",
    "Es una puerta transparente que sirve para salir al jardín.\n",
    ({"puerta transparente", "puerta", "puerta del sudeste", "puerta del jardín",
    "puerta del jardin"}),
    ([P_DOOR_TRANSPARENCY:1, P_MATERIAL: M_CRISTAL,
        P_DOOR_KNOCK_SOUND: SND_SUCESOS("llamar_puerta_cristal")]));

}
