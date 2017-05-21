/* Archivo: /d/simauria/comun/pnj/abadia/borracho.c
* Descripción: Un borracho en la taberna.
* Autor: Lug y Yalin.
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit PNJ("sherek/aldea/base");

create()
{
    ::create();
    SetStandard("Un borracho","humano",([ GC_TORPE:30 ]),GENERO_MASCULINO);
    SetName("Vorton");
    SetShort("Vorton el borracho");
    SetLong("Es un aldeano que ha bebido más de lo aconsejable.\nApenas puede "
        "tenerse en pie.\n");
    AddId(({"vorton","Vorton","borracho","aldeano","humano"}));
    SetHP(QueryMaxHP());
    SetDex(QueryDex()-4); //está muy borracho
    SetStr(QueryStr()-4); //está muy borracho
    InitChats(5,({"Vorton se tambalea ostensiblemente.\n",
        "Vorton grita: ¡Tabur, a ver ese vino! ¿Viene ya?\n",
        "Vorton eructa vergonzosamente.\n",
        "Vorton farfulla algo que ni él entiende.\n"}));
}
