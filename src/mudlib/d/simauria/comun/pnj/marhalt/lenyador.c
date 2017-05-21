/****************************************************************************
Fichero: leñador.c
Autor: Ratwor
Fecha: 29/01/2007
Descripción: el leñador del bosque de Marhalt.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <sounds.h>
inherit NPC;

public string f_cortar_madera(){
    if (resolve_file(MARH("nandor/bosque/zona_leñador")) == object_name(environment())){
        object casa = find_object(MARH("nandor/bosque/casa_leñador"));
        play_sound(environment(TP), SND_SUCESOS("hachazo"));
        tell_room(environment(), "El leñador corta un tronco de un hachazo.\n");
        if (casa){
            play_sound(casa, SND_SUCESOS("hachazo"),0,35);
            tell_room(MARH("nandor/bosque/casa_leñador"), "Se escucha cortar madera fuera "
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
    AddId(({"leñador", "corl", "Corl", "lenyador", "humano"}));
    SetShort("Corl el leñador");
    SetLong("Es un humano bajito y regordete, muy fornido y musculoso a pesar de sus "
        "años. Su cabello está empezando a encanecer, y en sus ojos se refleja la "
        "sabiduría del que ha vivido lo suyo.\n");
    SetAlign(120);
    SetSmell("Huele a sudor.\n");
    InitChats(5,({"El leñador mira a su alrededor.\n",
        "El leñador respira profundamente.\n",
        "El leñador prepara un tronco para cortarlo.\n", SF(f_cortar_madera),
        "El leñador te mira intrigado.\n", SF(f_cortar_madera)}));
    AddQuestion(({"rumores", "rumor"}), "Corl te dice: los rumores son ciertos.\n  Viví "
        "muchos años en la villa de Nandor con mi esposa Glayna y mi hijo Husbar, "
        "pero ambos murieron hace años, en una invasión orca que devastó el pueblo.\n"
        " Desde entonces vivo solo en este bosque.\n",1);
    AddQuestion(({"arboles", "árboles", "bosque"}), "Corl te dice: Busco siempre "
        "los árboles más gruesos para talarlos. Éste es un bosque joven y cuesta "
        "encontrar árboles de buen tronco, pero hay algunos que sirven y son buenos "
        "para el fuego.\n",1);
    AddQuestion(({"casa", "cabaña"}), "Corl te dice: La hice yo con mis propias "
        "manos cuando me vine a vivir aquí. En aquellos tiempos los árboles eran "
        "incluso más jóvenes que ahora, así que me costó encontrar la madera, pero ya"
        " ves que no ha quedado tan mal.\n",1);
    AddQuestion(({"retrato", "cuadro"}), "Corl te dice: Ah, sí, el retrato de la "
        "cabaña. Lo pintó un artista hace años. Son mi mujer y mi hijo, muertos hace "
        "tiempo a manos de los orcos. Siempre que lo miro recuerdo tantas cosas...\n",1);
    AddQuestion(({"familia","recuerdo", "recuerdos", "esposa", "Glayna", "gayna", "hijo",
        "Husbar", "husbar"}), "Corl te dice: Ah, como recuerdo a mi familia, mi "
        "esposa, mi hijo...\n",1);
    AddQuestion(({"guardabosques", "malgdher", "Malgdher"}), "Corl te dice: Es un "
        "medio elfo bastante interesante, algo retraído de la sociedad como yo, pero "
        "buena persona, le ayudé a construir su cabaña donde vive más hacia el sur.\n",1);
    AddQuestion(({"talla", "talla de madera", "figura", "figura de madera", "ninfa"}),
        "Corl te dice: me la hizo Malgdher el guardabosques, es un maestro en el "
        "arte de tallar figuras.\n",1);
    SetShrugMsg("Corl dice: yo no se nada.\n");
    arma=clone_object("/std/weapon");
    arma->SetStandard(WT_HACHA, 7, P_SIZE_MEDIUM, M_ACERO);
    arma->Set(P_SHORT, "un hacha de leñador");
    arma->Set(P_LONG,
        "Es una enorme hacha de leñador, algo vieja y usada, pero seguro que muy "
        "efectiva.\n");
    arma->AddId(({"hacha", "hacha de leñador"}));
    arma->SetNumberHands(2);
    arma->SetWeight(5000);
    AddItem(arma,REFRESH_REMOVE,SF(wieldme));
}
