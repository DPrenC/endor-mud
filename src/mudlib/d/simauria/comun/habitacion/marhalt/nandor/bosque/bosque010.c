/****************************************************************************
Fichero: bosque010.c
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
    SetIntLong(QueryIntLong()+ " El cauce del r�o se ensancha aqu� notablemente hacia "
        "el este, siendo m�s estrecho en direcci�n hacia la corriente al oeste.\n");
    AddExit("oeste","./bosque009");
    AddExit("norte","./bosque003");
    AddExit("nordeste", "./bosque004");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


