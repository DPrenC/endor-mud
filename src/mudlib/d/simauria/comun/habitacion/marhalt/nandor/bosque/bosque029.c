/****************************************************************************
Fichero: bosque029.c
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
    SetIntLong(QueryIntLong()+" El r�o abandona aqu� su estrechamiento del este, "
        "donde puedes ver 3 rocas en medio del r�o, aprovechando una ligera curva "
        "ensanchada en direcci�n a la corriente hacia el noroeste.\n El bosque pierde"
        " frondosidad por el oeste junto a la orilla.\n");
    AddDetail("rocas", "son tres rocas en medio del r�o donde hay un peque�o "
        "estrechamiento en el este.\n");
    AddDetail("curva", "El r�o tiene aqu� una curva que va de este en direcci�n "
        "noroeste, donde se ensancha notablemente.\n");
    AddExit("oeste","./bosque028");
    AddExit("este","./bosque030");
    AddExit("sur","./bosque034");
    AddExit("sudeste", "./bosque035");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


