/*

    Nombre      : bodegaEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : bodegas del poblado donde se guardan los toneles de sidra.

*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("la bodega de Enalel");
    SetIntLong("Est�s en un enorme edificio de madera donde multitud de "
  "toneles de sidra y estanter�as con botellas ocupan todo el espacio posible. "
    "Hacia el norte est� la salida hacia la calle de las cosechas.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddExit("norte",ENALHAB"poblado/calles/calle18");
    AddDoor("norte", "la puerta de la calle",
    "Una puerta para salir a la calle de las cosechas.\n",
    ({"puerta", "puerta de la calle", "puerta de salida", "puerta del norte"}));
}
