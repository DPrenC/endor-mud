/****************************************************************************
Fichero: esposa_noble.c
Autor: Ratwor
Fecha: 01/09/2006
Descripción: mujer del señor de nandor
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <money.h>
#include <sounds.h>
inherit NPC;
public int besada, ayuda;
create()
{
    ::create();
    SetStandard("lilet", "humano", ([GC_TORPE:15]), GENDER_FEMALE);
    SetShort("lilet Dhes-Bláin");
    SetLong("Lilet es la mujer del señor de Nandor. Es una mujer de unos cuarenta años "
        "y la verdad es que parece el experimento macabro de un hechicero con extraño"
        " sentido del humor, que hubiera intentado transformar un ogro en una mujer, "
        "pero sin mucho éxito.\n Lleva un vestido recargado de encajes y volantes, "
        "de un amarillo pálido que realza las bolsas de debajo de sus ojos y va a "
        "juego con el tono de su piel. Luce diamantes y perlas, en: orejas, cuello"
        ", brazos y dedos. Y luce una tiara lujosa sobre su estirada cabeza.\n");
    SetSmell("su perfume es fuerte y pesado, pero imposible de deducir a que huele.\n");
    SetCitizenship("nandor");
    SetNoise("al acercarte a ella un poco puedes oirla mascullar entre dientes: ¡ "
        "Asco de plebeyos!\n");
    AddId(({"humana", "lilet", "Lilet", "señora", "esposa", "mujer", "noble"}));
    InitChats(2, ({"Lilet te mira por encima del hombro y frunce el ceño.\n",
        "Lilet hace como que no te ha visto mientras admira encantada sus joyas.\n",
        "Lilet te mira de reojo observando todos tus movimientos.\n",
        "Lilet carraspea y fulminándote con sus ojillos porcinos te dice: si buscas "
        "a mi marido aquí no lo encontrarás.\n"}));
    AddQuestion(({"marido", "Marido"}), "Lilet te mira aburrida y te dice: no tengo ni "
        "la más mínima idéa de donde estará.\n");
    AddSubDetail(({"tiara"}), "Es una diadema de auténtico mithril. Tiene aspecto de "
        "ser valiosa.\n");
    AddSubDetail(({"ropa", "vestido"}), "Es de tafetán de un color oro pálido y está "
        "escesivamente recargado con volantes y encajes muy finos.\n");
    AddSubDetail(({"diamantes", "diamante"}), "Son diamantes del tamaño de una nuez y "
        "parecen auténticos.\n");
    AddSubDetail(({"perlas", "perla"}), "Unas preciosas perlas naturales que "
        "contrastan con la fealdad de la señora que las luce.\n");
}

init(){
    ::init();
    add_action("cmd_besar", "besar");
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    object proteccion;
    if (!ayuda)
    {
        tell_room(environment(), "Los gritos de la señora alertan a los guardias y "
        "acude un hombre de armas de inmediato para defenderla.\n");
        proteccion = clone_object(PNJ("marhalt/castillo/hombre_armas"));
        proteccion->move(environment(TO));
        ayuda=1;
    }

    return ::Defend(dam, dam_type, flags, &xtras);
}

public int cmd_besar(string str){
    if(str=="apasionadamente en los morros a la fea"){
        if(!besada){
            object dinero;
            dinero = MONEY_LIB->QueryMoneyObject(TP);
            if (!dinero) { dinero = clone_object("/obj/money"); dinero->move(TP); }
            dinero->AdjustMoney((["mithril":2]));
            write("Besas sin ningún pudor a la esposa del noble, la cual se queda "
            "desconcertada. Tras recuperar la compostura te apremia con unas monedas, "
            " sonriéndote, por lo bien que lo has hecho.\n");
            say(CAP(TNAME)+" besa a "+QueryName()+".\n",TP);
            besada=1;
            play_sound(environment(), SND_SUCESOS("beso"));
            return 1;
        }
        return notify_fail("No te aprobeches a ver si te va a ver algún guardia.\n",
        NOTIFY_NOT_VALID);
    }
}