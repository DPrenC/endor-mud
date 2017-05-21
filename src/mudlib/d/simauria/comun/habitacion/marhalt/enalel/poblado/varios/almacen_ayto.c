/*

    Nombre      : almacenAyuntamientoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Habitaci�n donde se guardan y catalogan las cosechas anuales antes del reparto.

*/

#include "./path.h"
inherit SCHEDULER_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("el almac�n comunitario de Enalel");
    SetIntLong("Est�s en una enorme sala de altos muros en la que se almacena la cosecha del a�o."
    "Hacia el este est� la puerta de salida del almac�n.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddExit("este",ENALHAB"poblado/varios/ayuntamiento");
    AddDoor("este", "la puerta de salida",
    "La puerta para volver al ayuntamiento.\n",
    ({"puerta", "puerta de salida", "puerta del este"}));
    SetMainRoom("./ayuntamiento");
    SetLastDest(ENALHAB"poblado/calles/calle06");
    SetNotifyExits(({}));
}
