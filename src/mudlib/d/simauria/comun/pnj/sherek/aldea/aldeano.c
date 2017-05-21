/* Archivo: /d/simauria/comun/pnj/abadia/aldeano.c
* Descripci�n: Aldeano base para la aldea y sus aleda�os.
* Autor: Lug y Yalin.
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit PNJ("sherek/aldea/base");

create()
{
    ::create();
    SetStandard("un aldeano","humano",([ GC_NINGUNO:30+d10() ]),GENERO_MASCULINO);
    SetIds(({"aldeano"}));
    SetShort("un aldeano ");
    SetLong("Es uno m�s de los pobres aldeanos que viven en Sloch.\nSu cara "
        "muestra esa expresi�n, mezcla de cansancio, desesperanza y malhumor "
        "de los que no tienen m�s ilusiones que seguir respirando a cada "
        "momento, agoviados por su trabajo.\n");
    SetHP(QueryMaxHP());
    SetNoGet(1);
    InitChats(5,({"El aldeano resopla un par de veces mientras descansa.\n",
        "El aldeano dice: No ser�a tan malo si nos pudi�ramos quedar toda la cosecha.\n",
        "El aldeano se limpia el sudor.\n",
        "El aldeano dice: Si pudiera reunir algo de dinero me ir�a de aqu�.\n",
        "El aldeano dice: Esto no es vida, demasiado trabajo y siempre pobres.\n"}));
}
