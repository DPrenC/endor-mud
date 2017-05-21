/****************************************************************************
Fichero: bosque023.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla norte del río.
Aquí lloriquea ahora el bardo del quest de gundistyr.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del río Kandal");

    AddExit("nordeste","./bosque016");
    AddExit("oeste","./bosque022");
    AddItem(PNJ("gundistyr/bardo"),REFRESH_DESTRUCT,1);
}


