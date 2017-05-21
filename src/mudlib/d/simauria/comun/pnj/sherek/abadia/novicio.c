/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/abadia/novicio.c
Autor: Lug y Yalin
Fecha: 17/09/2006
Descripción: Monje novicio para la abadía.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#include <spellmonster.h>
#include <skills.h>
inherit PNJ("sherek/monjebase");

create()
{
    ::create();
    SetStandard("un novicio","humano",([ GC_CLERIGO:70+d10() ]), GENERO_MASCULINO);
    AddId(({"novicio","monje novicio"}));
    SetShort("un monje novicio");
    SetLong("Es un monje de primer grado, que hace poco que ingresó en la "
        "orden, aunque, como es preceptivo para entrar al servicio de la "
        "diosa, ya es un guerrero consumado, fuerte y diestro, que necesita "
        "tan sólo el entrenamiento y la disciplina necesarios para "
        "convertirse en un experto militante de la orden.\nAl ser del grado "
        "más bajo, cuando no está entrenando o meditando, se dedica a las "
        "labores de limpieza, cocina o mantenimiento de la abadía.\n");
    SetCon(QueryCon()+4);
    SetInt(QueryInt()+8);
    SetDex(QueryDex()+1);
    SetStr(QueryStr()+1);
    SetHP(QueryMaxHP());
    AddItem(ARMA("sherek/abadia/maza"),REFRESH_REMOVE,1,SF(wieldme));
    AddItem(PROT("sherek/abadia/tunican"),REFRESH_REMOVE,1,SF(wearme));
    AddItem(PROT("sherek/abadia/zapatilla"),REFRESH_REMOVE,1,SF(wearme));
    SetGoChance(90);
}
