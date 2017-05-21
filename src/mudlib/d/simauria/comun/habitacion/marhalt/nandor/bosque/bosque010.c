/****************************************************************************
Fichero: bosque010.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla norte del río.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del río Kandal");
    SetIntLong(QueryIntLong()+ " El cauce del río se ensancha aquí notablemente hacia "
        "el este, siendo más estrecho en dirección hacia la corriente al oeste.\n");
    AddExit("oeste","./bosque009");
    AddExit("norte","./bosque003");
    AddExit("nordeste", "./bosque004");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


