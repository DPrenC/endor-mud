/****************************************************************************
Fichero: tirpa.c
Autor: Ratwor
Fecha: 30/10/2006
Descripción: la mujer de uthur
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();
    AddId(({"mujer", "humana", "tirpa"}));
    SetStandard("tirpa","humano",10,GENDER_FEMALE);
    SetShort("tirpa");
    SetLong("Tirpa es la mujer de Uthur.\n Es joven y risueña, contrastando notablemente"
        " con el viejo del marido.\n Se pasa la vida en cassa con las labores domésticas"
        " esperando a su esposo.\n");
    SetSmell("Huele suavemente a fragancia natural.\n");
    InitAChats(7,({"Tirpa grita escandalizada.\n", "Tirpa llora de pánico.\n"}));
    InitChats(3,({"Tirpa limpia un poco el polvo.\n", "tirpa te mira coqueta.\n",
        "Tirpa suspira.\n", "Tirpa te sonríe.\n",
        "Tirpa te dice: ¿te manda mi marido para algo?\n"}));
    AddQuestion(({"roalf","gulkas", "viejos"}), "Tirpa te dice: no se mucho de los "
    "amigos de mi marido.\n",1);
    AddQuestion(({"marido","esposo","uthur","viejo"}),"Tirpa te dice: siempre está por"
        " ahí hablando con sus amigotes y por casa no viene mucho, me tiene muy "
        "descuidada.\n",1);
    SetNoGet("Tirpa te dice: Mi marido no me satisface, pero eso no quiere decir "
    "que me deje manosear por cualquiera.\n");
    SetShrugMsg("Tirpa parece que no sabe que contestar.\n");
    SetCitizenship("nandor");
}
