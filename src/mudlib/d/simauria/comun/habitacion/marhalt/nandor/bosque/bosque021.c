/****************************************************************************
Fichero: bosque021.c
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
    SetIntLong(QueryIntLong()+ " M�s al oeste, dentro del agua hay 3 rocas, justo "
        "donde el r�o tiene un ligero estrechamiento y sus dos orillas est�n m�s "
        "pr�ximas.\n");
    AddDetail("rocas", "Son tres rocas que est�n dentro del agua m�s hacia el oeste.\n");
    AddExit("norte","./bosque015");
    AddExit("oeste","./bosque020");
    AddExit("este","./bosque022");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


