/****************************************************************************
Fichero: bosque023.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Orilla norte del r�o.
Aqu� lloriquea ahora el bardo del quest de gundistyr.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del r�o Kandal");

    AddExit("nordeste","./bosque016");
    AddExit("oeste","./bosque022");
    AddItem(PNJ("gundistyr/bardo"),REFRESH_DESTRUCT,1);
}


