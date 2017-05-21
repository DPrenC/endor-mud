/****************************************************************************
Fichero: bosque019.c
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
    SetIntLong(QueryIntLong()+ " El r�o viene hasta aqu� ensanchado desde la curva del "
        "sudeste, acompa�ado por un claro en el bosque que ves en el sur, tomando "
        "aqu� un tama�o m�s normal hacia el oeste en direcci�n a la corriente.\n");
    AddDetail("curva", "Desde el este, el r�o tom� una curva ensanchada hacia el "
        "noroeste y ahora vuelve a tener su direcci�n y tama�o normal hacia el oeste.\n");
    AddExit("sur","./bosque026");
    AddExit("oeste","./bosque018");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


