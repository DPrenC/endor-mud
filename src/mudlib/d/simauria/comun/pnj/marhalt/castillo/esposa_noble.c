/****************************************************************************
Fichero: esposa_noble.c
Autor: Ratwor
Fecha: 01/09/2006
Descripci�n: mujer del se�or de nandor
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
    SetShort("lilet Dhes-Bl�in");
    SetLong("Lilet es la mujer del se�or de Nandor. Es una mujer de unos cuarenta a�os "
        "y la verdad es que parece el experimento macabro de un hechicero con extra�o"
        " sentido del humor, que hubiera intentado transformar un ogro en una mujer, "
        "pero sin mucho �xito.\n Lleva un vestido recargado de encajes y volantes, "
        "de un amarillo p�lido que realza las bolsas de debajo de sus ojos y va a "
        "juego con el tono de su piel. Luce diamantes y perlas, en: orejas, cuello"
        ", brazos y dedos. Y luce una tiara lujosa sobre su estirada cabeza.\n");
    SetSmell("su perfume es fuerte y pesado, pero imposible de deducir a que huele.\n");
    SetCitizenship("nandor");
    SetNoise("al acercarte a ella un poco puedes oirla mascullar entre dientes: � "
        "Asco de plebeyos!\n");
    AddId(({"humana", "lilet", "Lilet", "se�ora", "esposa", "mujer", "noble"}));
    InitChats(2, ({"Lilet te mira por encima del hombro y frunce el ce�o.\n",
        "Lilet hace como que no te ha visto mientras admira encantada sus joyas.\n",
        "Lilet te mira de reojo observando todos tus movimientos.\n",
        "Lilet carraspea y fulmin�ndote con sus ojillos porcinos te dice: si buscas "
        "a mi marido aqu� no lo encontrar�s.\n"}));
    AddQuestion(({"marido", "Marido"}), "Lilet te mira aburrida y te dice: no tengo ni "
        "la m�s m�nima id�a de donde estar�.\n");
    AddSubDetail(({"tiara"}), "Es una diadema de aut�ntico mithril. Tiene aspecto de "
        "ser valiosa.\n");
    AddSubDetail(({"ropa", "vestido"}), "Es de tafet�n de un color oro p�lido y est� "
        "escesivamente recargado con volantes y encajes muy finos.\n");
    AddSubDetail(({"diamantes", "diamante"}), "Son diamantes del tama�o de una nuez y "
        "parecen aut�nticos.\n");
    AddSubDetail(({"perlas", "perla"}), "Unas preciosas perlas naturales que "
        "contrastan con la fealdad de la se�ora que las luce.\n");
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
        tell_room(environment(), "Los gritos de la se�ora alertan a los guardias y "
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
            write("Besas sin ning�n pudor a la esposa del noble, la cual se queda "
            "desconcertada. Tras recuperar la compostura te apremia con unas monedas, "
            " sonri�ndote, por lo bien que lo has hecho.\n");
            say(CAP(TNAME)+" besa a "+QueryName()+".\n",TP);
            besada=1;
            play_sound(environment(), SND_SUCESOS("beso"));
            return 1;
        }
        return notify_fail("No te aprobeches a ver si te va a ver alg�n guardia.\n",
        NOTIFY_NOT_VALID);
    }
}