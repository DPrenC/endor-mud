/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/abadia/monje.c
Autor: Lug y Yalin
Fecha: 01/09/2006
Descripción: Monje medio de la abadía.
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
    SetStandard("un monje","humano",([ GC_CLERIGO:80+d10() ]), GENERO_MASCULINO);
    SetName("El monje");
    AddId(({"numerario","monje numerario"}));
    SetShort("un monje numerario");
    SetLong("Es un monje de grado medio, con varios años de servicio en la "
        "orden.\nPor su entrenamiento está preparado para la lucha, es un "
        "buen guerrero y mago, por lo cuál, en el tiempo que le dejan libre "
        "su propio entrenamiento y la meditación, se dedica a entrenar a los "
        "monjes novicios.\n");
    SetCon(QueryCon()+8);
    SetInt(QueryInt()+12);
    SetDex(QueryDex()+2);
    SetStr(QueryStr()+2);
    SetHP(QueryMaxHP());
    AddItem(ARMA("vara"),REFRESH_REMOVE,1,SF(wieldme));
    AddItem(PROT("sherek/abadia/tunicam"),REFRESH_REMOVE,1,SF(wearme));
    AddItem(PROT("sherek/abadia/zapatilla"),REFRESH_REMOVE,1,SF(wearme));
    SetGoChance(90);
}
