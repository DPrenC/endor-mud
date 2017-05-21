
/****************************************************************************
Fichero: cam18.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria, Cruce de Gorat.
****************************************************************************/

#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    SetIntShort("un cruce de caminos");
    SetIntLong(QueryIntLong() + "Has llegado a un cruce, se une a este camino "
    "otro de similares caracteristicas que va hacia el oeste.\n Puedes ver un poste "
    "con un letrero.\n");
    AddDetail(({"poste", "letrero"}), "Es un robusto poste de madera, con un letrero "
    "clavado a él que tiene escritas unas indicaciones.\n");
    AddReadMsg(({"letrero", "cartel"}), " *Norte - Marhalt.\n *Oeste - Betwa.\n"
    " *Sur - Ishtria | Berat.\n");
    AddExit("sur","./cam19");
    AddExit("norte","./cam17");
    AddExit("oeste",CAMINOS "/simauria-gorat/camino01");
    AddExit("nordeste", MARH("nandor/bosque/bosque069"));
    AddExit("sudeste", MARH("nandor/bosque/bosque084"));
    HideExit("nordeste",1);
    HideExit("sudeste",1);
    AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT, d2());
}

