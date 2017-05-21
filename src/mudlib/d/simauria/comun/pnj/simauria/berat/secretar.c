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
        "sonríe maliciosamente mientras dice: Bueno, gracias a ti, le "
        "tuvimos al fresco una temporadita. Ahora creo que trabaja para "
        "buscarse la vida.\n";
    if ((TP->QueryAttribute("tienelibro")) || (TP->QueryAttribute("sabelibro"))) return "Nulamir "
        "se enoja contigo, y te grita: Ya te he dicho todo, déjame en paz, "
        "que bastante tengo con los ciudadanos despistados.\n";
    if (TP->QueryAttribute("sabeprueba"))
    {
        TP->SetAttribute("sabelibro",time());
        return "Nulamir te mira asombrado y te explica: Vaya, así que es "
            "cierto, el maldito Daryl está sobre la pista, ¿eh? Bien, bien. "
            "Mira: Hace años, llegó aquí un forastero llamado Marath, y a "
            "los pocos días, asesinó a uno de nuestros mejores ciudadanos, "
            "robándole el dinero que tenía en casa. Luego desapareció.\nA "
            "los pocos meses, nos llegaron rumores de que había ido a "
            "refugiarse muy lejos, en los dominios de los monjes de Sherek, "
            "muy al nordeste de aquí.\nSospechamos que cuando estuvo aquí "
            "iba disfrazado, así que nadie le reconocería, pero..., ¿sabes? "
            "El tipo era muy meticuloso. Se cuenta que siempre llevaba un "
            "libro conél, donde anotaba el producto de sus robos y lo que "
            "iba gastando, nunca se fió de los bancos.\nSi se encontrara ese "
            "libro, sería la prueba que necesitamos.\n";
    }
    return "Nulamir se rasca la cabeza y refunfuña: No sé lo que me dices. "
        "Tengo muchos problemas con el censo, y mi cabeza está un poco "
        "cansada.\nSi consigues averiguar algo más concreto, vuelve a ver.\n";
}

create()
{
    ::create();
   SetStandard("Nulamir","humano",15,GENERO_MASCULINO);
    SetShort("Nulamir, el secretario");
    SetLong("Es el secretario del ayuntamiento de Berat. Algo regordete, con barba "
    "desordenada y ropas algo viejas, quizá no es un buen ejemplo de formalidad.\n"
    " Pero aún así tiene un cierto respeto y autoridad entre los habitantes del pueblo.\n");
    SetCitizenship("berat");
    AddQuestion(({"censo","censar"}),"si quieres saber donde estas censado, "
        "pon consultar,si lo que quieres es censarte en Berat, pon censar.\n");
    AddQuestion(({"marath","marath","crimen","criminal","asesino","prueba"}),SF(informa));
    SetIds(({"nulamir","Nulamir","secretario","humano"}));
    InitChats(3,
        ({"Nulamir exclama: ¡Papeles, papeles y mas papeles!\n",
        "Nulamir saca punta a un lápiz y continúa repasando papeles.\n",
        "Nulamir se va al archivador y guarda allí varias carpetas.\n"}));
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
    write("Nulamir esquiva tu golpe escondiéndose bajo el mostrador. Al "
        "momento sale armado con un inmenso garrote y dice: Vaya parece que "
        "tenemos aquí un "+A_+" alborotador"+A_+".\nSin mediar mas palabra te "
        "golpea con él en el pecho de tal forma que por unos momentos te "
        "quedas sin respiración. Nulamir agita el garrote delante de tu cara, "
        "y te dice: Sigue así y te partiré la cara.\nHerid"+AO+" desistes de "
        "tu ataque.\n");
    tell_room(environment(TP), ({ MSG_SEE, W(NOMBRE+" ataca a Nulamir, pero "
        "éste se refugia tras el mostrador para luego aparecer de nuevo con "
        "un garrote con el que golpea a "+NOMBRE+" en el pecho, quien por un "
        "momento se queda sin respiración.\nNulamir advierte a "+NOMBRE+
        " que la próxima vez le pegará en serio y ést"+AE+", herid"+AO+
        ", desiste en su ataque.\n")}), ({ TP }));
    hp=TP->QueryHP();
    if (hp>15) TP->SetHP(hp-10);
    return 1;
}
*/
