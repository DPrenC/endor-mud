/****************************************************************************
Fichero: novia_soldado.c
Autor: Kastwey
Creación: 24/08/2005
Descripción: La novia del soldado de la posada
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>

inherit NPC;

int combatido;



public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    if (!combatido)
    // aún no ha combatido... así que se viste, que no mola que salga en bolas
    {
        combatido = 1;
        tell_room(environment(),W("La enana se levanta de la cama y, con un "
                                  "movimiento fluido, se coloca la sábana "
                                  "a modo de improvisada túnica.\n"));
    }

    return ::Defend(dam, dam_type, flags, &xtras);
}



string DescEnana()
{
    if (!combatido)
    {
        object soldado;
        string inicial;

        if (   (soldado = present("soldado_en_el_lio",environment()))
            && living(soldado))
        {
            inicial = "Ves a la enana, que supones es la pareja del soldado. ";
        }
        else
        {
            inicial = "Es una enana. ";
        }
        return W(inicial + "Está "
                 "cubierta hasta el cuello con la manta de la cama, y te "
                 "mira con unos ojos de vergüenza y molestia.\n");
    }
    return W("Es una enana. Como único atuendo, lleva lo que parece una "
             "sábana a modo de improvisada túnica. Te mira con ojos "
             "llameantes.\n");
}




public void create()
{
    ::create();
    SetStandard("una enana","enano",25,GENDER_FEMALE);
    AddId(({"enana","novia_soldado","novia del soldado"}));
    SetShort("una enana");
    SetLong(#'DescEnana);
}
public varargs void Die(int silent)
{
    if (combatido)
    // le clonamos la sábana
    {
        object sabana;
        sabana = clone_object(ARMOUR);
        sabana->SetStandard(AT_TUNICA,1,P_SIZE_GENERIC,M_TELA);
        sabana->SetShort("una sábana");
        sabana->SetLong(W("Se trata de una simple sábana de tela sin ningún "
                          "bordado o distintivo.\n"));
        sabana->AddId(({"sabana","sábana","sabana de tela","sábana de tela"}));
        sabana->move(TO);
    }
    return ::Die(silent);
}





public void reset()
{
    ::reset();
    if (!Fighting() && environment() && combatido)
    // está depié y con la sábana echada...
    // así que se tumba
    {
        tell_room(environment(),W("La enana se quita la sábana, y rápidamente "
                                  "se mete en la cama y se tapa hasta la "
                                  "barbilla.\n"));
        combatido = 0;
    }
}
