/* Archivo: /d/simauria/comun/pnj/abadia/ternero.c
* Descripción: Terneross para la granja.
* Autor: Lug y Yalin
*/
#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un ternero","ternero",4+d6(),GENERO_MASCULINO);
    SetShort("un ternero");
    SetLong("Es un lindo ternerillo, que casi no ha dejado de mamar aún.\nEstá "
        "bien alimentado; se nota que su madre es una buena vaca.\n");
    AddId("ternero");
    SetNoGet("El ternero se te escapa trotando.\n");
    SetHands(({({"los cuernos",3,3})}));
    SetHP(QueryMaxHP());
    InitChats(5,({"Un ternero rumia su comida.\n",
        "Un ternero se rasca con la pared.\n",
        "Un ternero muge tristemente.\n",
        "Un ternero corretea por el establo.\n"}));
    InitAChats(10,({"El ternero te embiste como puede.\n"}));
}

