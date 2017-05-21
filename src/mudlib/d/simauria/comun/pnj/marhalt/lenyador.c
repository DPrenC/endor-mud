/****************************************************************************
Fichero: le�ador.c
Autor: Ratwor
Fecha: 29/01/2007
Descripci�n: el le�ador del bosque de Marhalt.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <sounds.h>
inherit NPC;

public string f_cortar_madera(){
    if (resolve_file(MARH("nandor/bosque/zona_le�ador")) == object_name(environment())){
        object casa = find_object(MARH("nandor/bosque/casa_le�ador"));
        play_sound(environment(TP), SND_SUCESOS("hachazo"));
        tell_room(environment(), "El le�ador corta un tronco de un hachazo.\n");
        if (casa){
            play_sound(casa, SND_SUCESOS("hachazo"),0,35);
            tell_room(MARH("nandor/bosque/casa_le�ador"), "Se escucha cortar madera fuera "
            "de la casa.\n");
           return "";
        }
        return "";
    }
    return "";
}

create()
{
    object arma;
    ::create();
    SetStandard("Corl", "humano", ([GC_LUCHADOR:45+d4()]), GENDER_MALE);
    AddId(({"le�ador", "corl", "Corl", "lenyador", "humano"}));
    SetShort("Corl el le�ador");
    SetLong("Es un humano bajito y regordete, muy fornido y musculoso a pesar de sus "
        "a�os. Su cabello est� empezando a encanecer, y en sus ojos se refleja la "
        "sabidur�a del que ha vivido lo suyo.\n");
    SetAlign(120);
    SetSmell("Huele a sudor.\n");
    InitChats(5,({"El le�ador mira a su alrededor.\n",
        "El le�ador respira profundamente.\n",
        "El le�ador prepara un tronco para cortarlo.\n", SF(f_cortar_madera),
        "El le�ador te mira intrigado.\n", SF(f_cortar_madera)}));
    AddQuestion(({"rumores", "rumor"}), "Corl te dice: los rumores son ciertos.\n  Viv� "
        "muchos a�os en la villa de Nandor con mi esposa Glayna y mi hijo Husbar, "
        "pero ambos murieron hace a�os, en una invasi�n orca que devast� el pueblo.\n"
        " Desde entonces vivo solo en este bosque.\n",1);
    AddQuestion(({"arboles", "�rboles", "bosque"}), "Corl te dice: Busco siempre "
        "los �rboles m�s gruesos para talarlos. �ste es un bosque joven y cuesta "
        "encontrar �rboles de buen tronco, pero hay algunos que sirven y son buenos "
        "para el fuego.\n",1);
    AddQuestion(({"casa", "caba�a"}), "Corl te dice: La hice yo con mis propias "
        "manos cuando me vine a vivir aqu�. En aquellos tiempos los �rboles eran "
        "incluso m�s j�venes que ahora, as� que me cost� encontrar la madera, pero ya"
        " ves que no ha quedado tan mal.\n",1);
    AddQuestion(({"retrato", "cuadro"}), "Corl te dice: Ah, s�, el retrato de la "
        "caba�a. Lo pint� un artista hace a�os. Son mi mujer y mi hijo, muertos hace "
        "tiempo a manos de los orcos. Siempre que lo miro recuerdo tantas cosas...\n",1);
    AddQuestion(({"familia","recuerdo", "recuerdos", "esposa", "Glayna", "gayna", "hijo",
        "Husbar", "husbar"}), "Corl te dice: Ah, como recuerdo a mi familia, mi "
        "esposa, mi hijo...\n",1);
    AddQuestion(({"guardabosques", "malgdher", "Malgdher"}), "Corl te dice: Es un "
        "medio elfo bastante interesante, algo retra�do de la sociedad como yo, pero "
        "buena persona, le ayud� a construir su caba�a donde vive m�s hacia el sur.\n",1);
    AddQuestion(({"talla", "talla de madera", "figura", "figura de madera", "ninfa"}),
        "Corl te dice: me la hizo Malgdher el guardabosques, es un maestro en el "
        "arte de tallar figuras.\n",1);
    SetShrugMsg("Corl dice: yo no se nada.\n");
    arma=clone_object("/std/weapon");
    arma->SetStandard(WT_HACHA, 7, P_SIZE_MEDIUM, M_ACERO);
    arma->Set(P_SHORT, "un hacha de le�ador");
    arma->Set(P_LONG,
        "Es una enorme hacha de le�ador, algo vieja y usada, pero seguro que muy "
        "efectiva.\n");
    arma->AddId(({"hacha", "hacha de le�ador"}));
    arma->SetNumberHands(2);
    arma->SetWeight(5000);
    AddItem(arma,REFRESH_REMOVE,SF(wieldme));
}
