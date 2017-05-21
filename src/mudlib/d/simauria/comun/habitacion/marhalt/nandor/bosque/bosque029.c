/****************************************************************************
Fichero: bosque029.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla sur del río.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();

    SetIntShort("la orilla sur del río Kandal");
    SetIntLong(QueryIntLong()+" El río abandona aquí su estrechamiento del este, "
        "donde puedes ver 3 rocas en medio del río, aprovechando una ligera curva "
        "ensanchada en dirección a la corriente hacia el noroeste.\n El bosque pierde"
        " frondosidad por el oeste junto a la orilla.\n");
    AddDetail("rocas", "son tres rocas en medio del río donde hay un pequeño "
        "estrechamiento en el este.\n");
    AddDetail("curva", "El río tiene aquí una curva que va de este en dirección "
        "noroeste, donde se ensancha notablemente.\n");
    AddExit("oeste","./bosque028");
    AddExit("este","./bosque030");
    AddExit("sur","./bosque034");
    AddExit("sudeste", "./bosque035");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


