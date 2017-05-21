/****************************************************************************
Fichero: bosque022.c
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

    AddExit("este","./bosque023");
    AddExit("oeste","./bosque021");
    AddExit("noroeste", "./bosque015");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


