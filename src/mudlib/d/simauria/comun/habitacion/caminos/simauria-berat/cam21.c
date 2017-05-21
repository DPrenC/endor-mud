
/****************************************************************************
Fichero: cam21.c
Autor: Ratwor
Fecha: 16/06/2007
Descripción: Camino Ishtria-Berat.
****************************************************************************/


#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();
    SetIntShort("un cruce de caminos");
    SetIntLong(QueryIntLong()+ " Junto al camino puedes ver un poste con un cartel "
    "colgando.\n");
    AddDetail("poste", "Es un poste robusto de madera bien clavado en el suelo, tiene "
    "un cartel con unas indicaciones.\n");
    AddDetail(({"letrero", "cartel", "indicaciones", "indicación", "indicacion"}),
    "Ves un cartel con unas indicaciones escritas.\n");
    AddReadMsg(({"letrero", "cartel", "indicaciones", "indicación", "indicacion"}),
    " *Norte - Ishtria | Betwa | Marhalt.\n *Sur - Berat.\n *Oeste - Nyne.\n");

    AddExit("sur", "./cam22");
    AddExit("noroeste","./cam20");
    AddExit("oeste",CNYNEBERAT("cam43"));
    AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT, d2());
}
