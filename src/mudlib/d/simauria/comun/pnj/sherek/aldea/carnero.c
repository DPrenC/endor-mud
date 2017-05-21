/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/aldea/carnero.c
Autor: Lug y Yalin
Fecha: 17/01/2007
Descripción: Carnero para la granja de la aldea.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un carnero","oveja",([ GC_LUCHADOR:15+d4() ]),GENERO_MASCULINO);
    SetShort("un carnero");
    SetLong("Es un macho de oveja, grande, fuerte y de mal humor.\nHay que "
        "tener cuidado, pues no suele gustarles que invadan su rebaño.\n");
    AddId(({"carnero","macho"}));
    SetWeight(100000);
    SetNoGet("no, no es buena idea, parece furioso.\n");
    InitChats(5,
        ({"El carnero da topetazos contra la pared.\n",
        "El carnero te mira y resopla.\n",
        "El carnero bala amenazadoramente.\n",
        "El carnero rumia sus pensamientos, y otras hierbas que ha comido en "
        "la pradera.\n"}));
}
