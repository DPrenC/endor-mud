/****************************************************************************
Fichero: /d/simauria/comun/quest/sherek/abuelo.c
Autor: Lug y Yalin
Fecha: 07/01/2007
Descripción: abuelo del niño, pescando en el río.
****************************************************************************/

#include "path.h"
#include <properties.h>
inherit PNJ("sherek/aldea/base");

string informa()
{
    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) || (TP->QueryAttribute("tienepiedra"))) return "Sí, "
        "ya lo saben todos, y no paran de alabarte. Debes ser muy valiente "
        "para haber ido hasta allí para complacer a un niño.\n";
    if (TP->QueryAttribute("sabepiedra")) return "El vejete te mira "
        "preocupado y te susurra: Vaya, ¿ya te ha engatusado mi nieto con "
        "sus historias? Bien, bien. Es un niño muy bueno, pero un soñador. "
        "El caso es que yo sólo le dije, que por estas montañas, hubo hace "
        "mucho tiempo un yacimiento de piedras preciosas, y los enanos las "
        "extrajeron todas y se fueron, pero nadie ha encontrado el sitio.\nSi "
        "alguien sabe algo de eso, sin duda será algún enano que tenga la "
        "suficiente autoridad para conocer toda la historia de su raza.\n";
    return "El anciano gruñe: ¿Minas? No sé, los monjes nunca buscan mineros, "
        "no creo que haya ninguna por aquí.\n";
}

create()
{
    ::create();
    SetStandard("un viejo","humano",20,GENERO_MASCULINO);
    SetName("el abuelo");
    AddId(({"abuelo","viejo","aldeano","vejete","pescador","humano","to_delete"}));
    SetShort("un viejo pescando");
    SetLong("Es un viejo aldeano, liberado ya de sus trabajos en la aldea, "
        "que mata el tiempo que le sobra pescando en el río.\n");
    SetHP(QueryMaxHP());
    SetAlign(100);
    AddQuestion(({"minas","mina"}),SF(informa),1);
    AddQuestion(({"niño","ninyo","nieto","nietecito"}),"Sí, es un niño "
        "encantador, pero tiene la cabeza llena de fantasías. Ahora le ha "
        "dado por buscar tesoros... ¿Ves? Está allí, en aquel remanso.\n");
    InitChats(5,({"El viejo maldice: ¡Qué diablos! Hoy no voy a pescar nada.\n",
        "El viejo te pregunta: ¿Has visto a mi nietecito? ¿Verdad que es guapo?\n",
        "El viejo suspira: El río está revuelto hoy, los peces no saldrán arriba.\n",
        "El viejo reniega: Hoy tendremos que comer verduras.\n"}));
}
