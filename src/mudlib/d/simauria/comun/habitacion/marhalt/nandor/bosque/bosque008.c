/****************************************************************************
Fichero: bosque008.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Orilla norte del r�o.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del r�o Kandal");

    AddExit("norte","./bosque002");
    AddExit("este","./bosque009");
    AddExit("noroeste", "./bosque001");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


