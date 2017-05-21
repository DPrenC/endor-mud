/****************************************************************************
Fichero: bosque033.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Orilla sur del r�o.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla sur del r�o Kandal");
    AddExit("oeste","./bosque032");
    AddExit("sur","./bosque038");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


