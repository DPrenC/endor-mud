/*

    Nombre      : ayuntamientoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Ayuntamiento de Enalel

*/

#include "./path.h"
#include <nightday.h>
#include <door.h>

inherit SCHEDULER_ROOM;


create() {
    ::create();

    SetIntBright(35);
    SetLocate("Poblado de Enalel");
    SetIntShort("el ayuntamiento de Enalel");
    SetIntLong("Est�s en el ayuntamiento de Enalel. "
    "Es un edificio de altos muros cuyo principal material es la madera.\n"
    "Los ciudadanos del poblado se re�nen aqu� para decidir e informarse de los "
    "asuntos relacionados con la poblaci�n.\n"
    "La sala de reuniones del concilio se encuentra en la planta superior, junto con "
    "los distintos despachos de los empleados del ayuntamiento.\n");
    SetIntNoise("Las conversaciones y cuchicheos parecen llenar el ambiente.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddExit("norte",ENALHAB"poblado/calles/calle06");
    AddExit("oeste", "./almacen_ayto");
    AddExit("arriba",ENALHAB"poblado/varios/sala_ayto");
    AddItem(ENALPNJ"ancianos/librath",REFRESH_DESTRUCT);
    AddDoor("oeste", "la puerta del almac�n",
    "Es una peque�a puerta que da acceso al almac�n comunitario del poblado.\n",
    ({"puerta", "puerta del almacen", "puerta del almac�n", "puerta del oeste"}));
    AddDoor("norte", "la puerta de la calle",
    "La puerta para salir a la calle del comercio.\n",
    ({"puerta", "puerta del norte", "puerta de salida", "puerta de la calle"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetLastDest(ENALHAB"poblado/calles/calle06");
    SetNotifyExits("norte");
    SetAssociatedRooms(({"./almacen_ayto", "./sala_ayto"}));
    SetSchedulerID("librath");
    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
}
