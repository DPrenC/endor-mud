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
    SetStandard("un guardia","medioelfo",([GC_LUCHADOR: 18+random(5)]),GENERO_MASCULINO);
    SetShort("un guardia de la familia Fhainfos");
    SetLong("Es un medio elfo fornido. Parece permanecer siempre alerta observando "
    "todos tus movimientos.\n");
    SetIds(({"elfo","medio elfo","semielfo","medioelfo","guardia","guardia de enalel"}));
    SetAlign(300);
    SetStr(QueryStr()+1);
    SetDex(QueryDex()+2);
    AddItem(ARMAS("espada_larga"),REFRESH_REMOVE,SF(wieldme));
}
