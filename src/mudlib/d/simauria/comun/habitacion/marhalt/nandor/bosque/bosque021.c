/****************************************************************************
Fichero: bosque021.c
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
    SetIntLong(QueryIntLong()+ " Más al oeste, dentro del agua hay 3 rocas, justo "
        "donde el río tiene un ligero estrechamiento y sus dos orillas están más "
        "próximas.\n");
    AddDetail("rocas", "Son tres rocas que están dentro del agua más hacia el oeste.\n");
    AddExit("norte","./bosque015");
    AddExit("oeste","./bosque020");
    AddExit("este","./bosque022");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


