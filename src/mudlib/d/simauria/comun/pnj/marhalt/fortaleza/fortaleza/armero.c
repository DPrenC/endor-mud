/*
DESCRIPCION :  armero
FICHERO     : armero.c
MODIFICACION: 17-07-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <rooms.h>
#include <properties.h>
inherit NPC;

create()
{
    ::create();
   SetStandard("Ralted","humano",31,GENERO_MASCULINO);
    SetShort("Ralted");
    SetLong("Ralted es un humano. Parece muy ocupado, mientras curte a una velocidad de "
        "vértigo una armadura de cuero. No parece prestarte ninguna atención.\n");
    SetIds(({"armero","ralted","tendero"}));
    SetAggressive(0);
    Set(P_CANT_LURE,1);
    SetAlign(0);
}
