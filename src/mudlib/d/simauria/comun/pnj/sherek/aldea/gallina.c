/* Archivo:         gallina.c
* Descripción:      gallina para la granja de Sloch.
* Autor:            Yalin y Lug.
* Fecha:            18/05/2006
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("una gallina","gallina",([ GC_TORPE:6+d4() ]),GENERO_FEMENINO);
    SetShort("una gallina");
    SetLong("Se trata de una graciosa gallinita de color parduzco con manchas blancas en algunas "
            "partes de su cuerpo. Su cresta está encarnada, por lo que deduces que seguramente "
            "pondrá bastantes huevos a lo largo de la semana.\n");
    AddId("gallina");
    SetMaxHP(87);
    SetHP(QueryMaxHP());
    SetInt(1);
    SetStr(9);
    SetDex(10);
    SetHands(({({"pico",3,1})}));
    SetWeight(4000);
    SetNoGet("La gallina huye batiendo las alas y cacareando.\n");
    InitChats(5,({"La gallina se escarva las plumas buscando piojos.\n",
                "La gallina revolotea.\n",
                "La gallina dice: ¡eureka!\n",
                "La gallina corretea por las varas del gallinero.\n"}));
}
