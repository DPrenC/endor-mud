/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/abadia/superior.c
Autor: Lug y Yalin
Fecha: 01/09/2006
Descripción: Monje superior de la abadía.
****************************************************************************/

#include "path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>
#include <skills.h>
#include <spellmonster.h>
inherit PNJ("sherek/monjebase");

create()
{
    ::create();
    SetStandard("un superior","humano",([ GC_CLERIGO:90+d10() ]), GENERO_MASCULINO);
    AddId(({"superior","monje superior"}));
    SetShort("un monje superior");
    SetLong("Es un monje de grado superior, con muchos años de servicio en "
        "la orden.\nPor su alto nivel de entrenamiento es un experto "
        "guerrero y mago, por lo cuál, en el tiempo que le dejan libre su "
        "propio entrenamiento y la meditación, se dedica a entrenar a los "
        "monjes numerarios.\n");
    SetCon(QueryCon()+12);
    SetInt(QueryInt()+15);
    SetDex(QueryDex()+3);
    SetStr(QueryStr()+3);
    SetHP(QueryMaxHP());
    Set(P_CANT_LURE,1);
    AddItem("/guilds/conjuradores/obj/vara_metal",REFRESH_REMOVE,1,SF(wieldme));
    AddItem(PROT("sherek/abadia/tunicas"),REFRESH_REMOVE,1,SF(wearme));
    AddItem(PROT("sherek/abadia/zapatilla"),REFRESH_REMOVE,1,SF(wearme));
    SetGoChance(90);
}
