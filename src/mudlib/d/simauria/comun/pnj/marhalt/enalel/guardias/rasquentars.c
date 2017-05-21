/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "./path.h"
#include <guild.h>
#include <properties.h>

inherit ENALPNJ"guardia_base";

create(){
    ::create();
    SetStandard("un guardia","humano",([GC_LUCHADOR: 18+random(5)]),GENERO_MASCULINO);
    SetShort("un guardia de la familia Rasquentar");
    SetLong("Es un humano de aspecto astuto y pendenciero. Parece desconfiar "
    "de tus intenciones y no te quita ojo de encima.\n");
    SetAlign(100);
    SetStr(QueryStr()+3);
    SetDex(QueryDex()+1);
    AddItem(ARMAS("espada_ancha"),REFRESH_REMOVE,SF(wieldme));
}
