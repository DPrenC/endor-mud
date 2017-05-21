/****************************************************************************
Fichero: /d/simauria/comun/quest/sherek/abuelo.c
Autor: Lug y Yalin
Fecha: 07/01/2007
Descripci�n: abuelo del ni�o, pescando en el r�o.
****************************************************************************/

#include "path.h"
#include <properties.h>
inherit PNJ("sherek/aldea/base");

string informa()
{
    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) || (TP->QueryAttribute("tienepiedra"))) return "S�, "
        "ya lo saben todos, y no paran de alabarte. Debes ser muy valiente "
        "para haber ido hasta all� para complacer a un ni�o.\n";
    if (TP->QueryAttribute("sabepiedra")) return "El vejete te mira "
        "preocupado y te susurra: Vaya, �ya te ha engatusado mi nieto con "
        "sus historias? Bien, bien. Es un ni�o muy bueno, pero un so�ador. "
        "El caso es que yo s�lo le dije, que por estas monta�as, hubo hace "
        "mucho tiempo un yacimiento de piedras preciosas, y los enanos las "
        "extrajeron todas y se fueron, pero nadie ha encontrado el sitio.\nSi "
        "alguien sabe algo de eso, sin duda ser� alg�n enano que tenga la "
        "suficiente autoridad para conocer toda la historia de su raza.\n";
    return "El anciano gru�e: �Minas? No s�, los monjes nunca buscan mineros, "
        "no creo que haya ninguna por aqu�.\n";
}

create()
{
    ::create();
    SetStandard("un viejo","humano",20,GENERO_MASCULINO);
    SetName("el abuelo");
    AddId(({"abuelo","viejo","aldeano","vejete","pescador","humano","to_delete"}));
    SetShort("un viejo pescando");
    SetLong("Es un viejo aldeano, liberado ya de sus trabajos en la aldea, "
        "que mata el tiempo que le sobra pescando en el r�o.\n");
    SetHP(QueryMaxHP());
    SetAlign(100);
    AddQuestion(({"minas","mina"}),SF(informa),1);
    AddQuestion(({"ni�o","ninyo","nieto","nietecito"}),"S�, es un ni�o "
        "encantador, pero tiene la cabeza llena de fantas�as. Ahora le ha "
        "dado por buscar tesoros... �Ves? Est� all�, en aquel remanso.\n");
    InitChats(5,({"El viejo maldice: �Qu� diablos! Hoy no voy a pescar nada.\n",
        "El viejo te pregunta: �Has visto a mi nietecito? �Verdad que es guapo?\n",
        "El viejo suspira: El r�o est� revuelto hoy, los peces no saldr�n arriba.\n",
        "El viejo reniega: Hoy tendremos que comer verduras.\n"}));
}
