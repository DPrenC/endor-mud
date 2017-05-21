/****************************************************************************
Fichero: calle7.c
Autor: Ratwor
Fecha: 12/08/2007
Descripción: Una calle de Nandor a las afueras.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetPreIntShort("cerca de");
    SetIntShort("un cruce");
    SetIntLong("Te hallas cerca de un cruce de caminos,que se encuentra al sur de "
        "tu posición actual.\n  Estás en las afueras de Nandor, en una zona especialmente"
        " polvorienta donde los caminos laterales parecen fusionarse con la calle.\n"
        "  Casi no se oye nada, porque esta parte de la villa está prácticamente "
        "desierta.\n  Al sudeste, se recorta en la distancia el bosque de Marhalt.\n");
    AddDetail("bosque", "A lo lejos divisas, aunque aún borroso, el bosque de Marhalt"
        " que se extiende al sudeste de la villa.\n");

    SetIndoors(0);

    AddExit("norte","./calle6");
    AddExit("sur","./cruce");
    AddItem(PNJ("marhalt/perro"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("marhalt/granjero_nandor"),REFRESH_DESTRUCT,1);
}

