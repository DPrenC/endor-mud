/****************************************************************************
Fichero: taquillero.c
Autor: Ratwor
Fecha: 27/01/2008
Descripci�n: Un taquillero para las paradas de las diligencias.
****************************************************************************/
#include <properties.h>
inherit NPC;

create(){
    ::create();
    SetStandard("el taquillero", "humano", 15, GENDER_MALE);
    SetShort("el taquillero");
    AddId(({"taquillero", "hombre"}));
    SetLong("�ste es el taquillero de �sta parada de diligencias, se encarga de "
    "vender los billetes para poder viajar con cualquiera de las diligencias que tienen "
    "parada en este lugar.\n");
    AddQuestion(({"diligencia", "viaje", "billete", "pasaje", "itinerario", "precio"}),
    "El taquillero dice:\n ante cualquier duda puedes leer el cartel.\n");
    SetIVision(-20);
}


