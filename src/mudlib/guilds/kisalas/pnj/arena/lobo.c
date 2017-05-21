/****************************************************************************
Fichero: lobo.c
Autor: Riberales
Fecha: 28/02/2006
Descripción: Un lobo para las Kisalas.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <damage.h>

inherit DEPREDADOR;

public int no_es_comestible(object victima)
{
    int res = ::no_es_comestible(victima);
    object lobos;

    if (res) return res;
    if (sizeof((lobos = filter(all_inventory(environment()),
                      (:$1 != TO && $1->QueryRace() == "lobo":)))) > 3)
    { // si hay más de tres lobos sin contar a este, se atreben a atacar
        call_other(lobos,"AddEnemy", victima);
        return 0;
    }
    return 1;
}


create()
{
    ::create();
    SetStandard("un lobo","lobo",13+random(3),GENDER_MALE);
    SetShort("un lobo");
    SetLong("Se trata de un lobo de aspecto feroz. Te muestra sus dientes de "
            "manera amenazadora. No para de salivar, y te mira "
            "constantemente.\n");

    AddPrey(({"zorro","conejo"}));
    SetIds(({"lobo"}));
    SetHands(({({"los dientes",DT_PIERCE,4})}));

    InitChats(3,({"El lobo comienza a dar vueltas a tu alrededor.\n"}));
}

