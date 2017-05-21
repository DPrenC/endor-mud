/****************************************************************************
Fichero: novia_soldado.c
Autor: Kastwey
Creaci�n: 24/08/2005
Descripci�n: La novia del soldado de la posada
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
    // a�n no ha combatido... as� que se viste, que no mola que salga en bolas
    {
        combatido = 1;
        tell_room(environment(),W("La enana se levanta de la cama y, con un "
                                  "movimiento fluido, se coloca la s�bana "
                                  "a modo de improvisada t�nica.\n"));
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
        return W(inicial + "Est� "
                 "cubierta hasta el cuello con la manta de la cama, y te "
                 "mira con unos ojos de verg�enza y molestia.\n");
    }
    return W("Es una enana. Como �nico atuendo, lleva lo que parece una "
             "s�bana a modo de improvisada t�nica. Te mira con ojos "
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
    // le clonamos la s�bana
    {
        object sabana;
        sabana = clone_object(ARMOUR);
        sabana->SetStandard(AT_TUNICA,1,P_SIZE_GENERIC,M_TELA);
        sabana->SetShort("una s�bana");
        sabana->SetLong(W("Se trata de una simple s�bana de tela sin ning�n "
                          "bordado o distintivo.\n"));
        sabana->AddId(({"sabana","s�bana","sabana de tela","s�bana de tela"}));
        sabana->move(TO);
    }
    return ::Die(silent);
}





public void reset()
{
    ::reset();
    if (!Fighting() && environment() && combatido)
    // est� depi� y con la s�bana echada...
    // as� que se tumba
    {
        tell_room(environment(),W("La enana se quita la s�bana, y r�pidamente "
                                  "se mete en la cama y se tapa hasta la "
                                  "barbilla.\n"));
        combatido = 0;
    }
}
