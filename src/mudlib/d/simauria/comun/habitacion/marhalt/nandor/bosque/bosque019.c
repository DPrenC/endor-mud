/****************************************************************************
Fichero: bosque019.c
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
    SetIntLong(QueryIntLong()+ " El río viene hasta aquí ensanchado desde la curva del "
        "sudeste, acompañado por un claro en el bosque que ves en el sur, tomando "
        "aquí un tamaño más normal hacia el oeste en dirección a la corriente.\n");
    AddDetail("curva", "Desde el este, el río tomó una curva ensanchada hacia el "
        "noroeste y ahora vuelve a tener su dirección y tamaño normal hacia el oeste.\n");
    AddExit("sur","./bosque026");
    AddExit("oeste","./bosque018");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


