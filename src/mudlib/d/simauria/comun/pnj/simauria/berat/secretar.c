/*
DESCRIPCION  : Nulamir, el secretario del ayuntamiento
FICHERO      : /d/simauria/comun/pnj/secretar.c
MODIFICACION : 28-10-99 [jorus@Simauria]creacion;10-6-00[Maler]elimino re-
tornos de carro;enmascaro los comandos magia y lanzar pa q no le pelen tan
facilmente;sustituyo defines. Meto wrap en todas las descs, pq todas tan mal
tabulas
--------------------------------------------------------------------------------
*/
#include "path.h"
#include <properties.h>
#include <messages.h>
inherit NPC;

#define AE      (TP->QueryGender()==2?"a":"e")
#define AO      (TP->QueryGenderEndString())
#define A_      (TP->QueryGender()==2?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))

string informa()
{
    if (QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) return "Nulamir "
        "sonr�e maliciosamente mientras dice: Bueno, gracias a ti, le "
        "tuvimos al fresco una temporadita. Ahora creo que trabaja para "
        "buscarse la vida.\n";
    if ((TP->QueryAttribute("tienelibro")) || (TP->QueryAttribute("sabelibro"))) return "Nulamir "
        "se enoja contigo, y te grita: Ya te he dicho todo, d�jame en paz, "
        "que bastante tengo con los ciudadanos despistados.\n";
    if (TP->QueryAttribute("sabeprueba"))
    {
        TP->SetAttribute("sabelibro",time());
        return "Nulamir te mira asombrado y te explica: Vaya, as� que es "
            "cierto, el maldito Daryl est� sobre la pista, �eh? Bien, bien. "
            "Mira: Hace a�os, lleg� aqu� un forastero llamado Marath, y a "
            "los pocos d�as, asesin� a uno de nuestros mejores ciudadanos, "
            "rob�ndole el dinero que ten�a en casa. Luego desapareci�.\nA "
            "los pocos meses, nos llegaron rumores de que hab�a ido a "
            "refugiarse muy lejos, en los dominios de los monjes de Sherek, "
            "muy al nordeste de aqu�.\nSospechamos que cuando estuvo aqu� "
            "iba disfrazado, as� que nadie le reconocer�a, pero..., �sabes? "
            "El tipo era muy meticuloso. Se cuenta que siempre llevaba un "
            "libro con�l, donde anotaba el producto de sus robos y lo que "
            "iba gastando, nunca se fi� de los bancos.\nSi se encontrara ese "
            "libro, ser�a la prueba que necesitamos.\n";
    }
    return "Nulamir se rasca la cabeza y refunfu�a: No s� lo que me dices. "
        "Tengo muchos problemas con el censo, y mi cabeza est� un poco "
        "cansada.\nSi consigues averiguar algo m�s concreto, vuelve a ver.\n";
}

create()
{
    ::create();
   SetStandard("Nulamir","humano",15,GENERO_MASCULINO);
    SetShort("Nulamir, el secretario");
    SetLong("Es el secretario del ayuntamiento de Berat. Algo regordete, con barba "
    "desordenada y ropas algo viejas, quiz� no es un buen ejemplo de formalidad.\n"
    " Pero a�n as� tiene un cierto respeto y autoridad entre los habitantes del pueblo.\n");
    SetCitizenship("berat");
    AddQuestion(({"censo","censar"}),"si quieres saber donde estas censado, "
        "pon consultar,si lo que quieres es censarte en Berat, pon censar.\n");
    AddQuestion(({"marath","marath","crimen","criminal","asesino","prueba"}),SF(informa));
    SetIds(({"nulamir","Nulamir","secretario","humano"}));
    InitChats(3,
        ({"Nulamir exclama: �Papeles, papeles y mas papeles!\n",
        "Nulamir saca punta a un l�piz y contin�a repasando papeles.\n",
        "Nulamir se va al archivador y guarda all� varias carpetas.\n"}));
}

/*
init()
{
    ::init();
    add_action("matar_cmd","matar");
    add_action("matar_cmd","magia");
    add_action("matar_cmd","lanzar");
}

int matar_cmd()
{
    object who;
    int hp;
    who=TP;
    who->StopHunting(TO);
    write("Nulamir esquiva tu golpe escondi�ndose bajo el mostrador. Al "
        "momento sale armado con un inmenso garrote y dice: Vaya parece que "
        "tenemos aqu� un "+A_+" alborotador"+A_+".\nSin mediar mas palabra te "
        "golpea con �l en el pecho de tal forma que por unos momentos te "
        "quedas sin respiraci�n. Nulamir agita el garrote delante de tu cara, "
        "y te dice: Sigue as� y te partir� la cara.\nHerid"+AO+" desistes de "
        "tu ataque.\n");
    tell_room(environment(TP), ({ MSG_SEE, W(NOMBRE+" ataca a Nulamir, pero "
        "�ste se refugia tras el mostrador para luego aparecer de nuevo con "
        "un garrote con el que golpea a "+NOMBRE+" en el pecho, quien por un "
        "momento se queda sin respiraci�n.\nNulamir advierte a "+NOMBRE+
        " que la pr�xima vez le pegar� en serio y �st"+AE+", herid"+AO+
        ", desiste en su ataque.\n")}), ({ TP }));
    hp=TP->QueryHP();
    if (hp>15) TP->SetHP(hp-10);
    return 1;
}
*/
