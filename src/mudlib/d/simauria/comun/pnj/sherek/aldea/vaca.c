/* Archivo: /d/simauria/comun/pnj/abadia/vaca.c
* Descripción: Vacas para la granja.
* Autor: Lug y Yalin
*/
#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("una vaca","vaca",10+d10(),GENERO_FEMENINO);
    SetIds(({"vaca"}));
    SetShort("una vaca");
    SetLong("Es una hermosa vaca, de turgentes y llenas ubres.\nSin duda es de "
        "buena raza lechera.\n");
    AddId("vaca");
    SetNoGet("No hagas tonterías, te arriesgas a que te den una coz.\n");
    SetHands(({({"los cuernos",3,6})}));
    SetHP(QueryMaxHP());
    InitChats(5,({"Una vaca rumia su comida.\n",
        "Una vaca se rasca con la pared.\n",
        "Una vaca muge aburrida.\n",
        "Una vaca espanta una mosca con el rabo.\n"}));
    InitAChats(10,({"La vaca te embiste furiosa.\n"}));
}

