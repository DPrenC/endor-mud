/****************************************************************************
Fichero: depredador.c
Autor: Kastwey
Fecha: 01/03/2006
Descripción: Animal depredador...
****************************************************************************/


#include "path.h"
#define TIEMPO_RED_FOOD 30

inherit ANIMAL_BASE;

private int tiempo;
private string *preys = ({});

public string *AddPrey(mixed prey)
{
    if (stringp(prey)) prey = ({prey});
    return preys = m_indices(mkmapping(preys + prey));
}

public string *RemovePrey(mixed s)
{
    if (stringp(s)) s = ({s});
    return preys -= s;
}

public string *SetPreys(string *s) { return preys = s ||({}); }
public string *QueryPreys() { return preys; }

public int no_es_comestible(object ob)
// Si ve a una presa, se la intenta cargar, y luego se la intenta zampar
{
    if (!ob || member(preys, ob->QueryRace()) < 0 || QueryFood() >= QueryMaxFood())
    {
        return 1;
    }

    return 0;
}

create()
{
    ::create();
   SetAggressive(2);
    SetFriendFunction(SF(no_es_comestible));
}

public void comer_victima(string quien)
{
    object ob;
    if (!quien || !ob = present(quien,environment()) || living(ob) || ob == TO) return;
    if (ob->QuerySize() > QuerySize() || ob->QueryWeight() > QueryWeight())
    // no puede comérselo de una vez, así que solo se come un poquito.
    {
        tell_room(environment(), CAP(QueryShort()) + " da varios mordiscos a " +
                                 ob->QueryShort() + ".\n");
        AddFood(10);
        ob->SetWeight(ob->QueryWeight() - QueryWeight() / 4);
        ob->SetName(ob->QueryName() + " a medio comer");

        return;
    }
    tell_room(environment(), CAP(QueryShort()) + " se come " + ob->QueryShort() +
                             " de varias dentelladas.\n");
    AddFood(10);
    ob->remove();
}



public void catch_tell(string s)
{
    string quien;
    if (sscanf(s, "Has matado a %s.",quien) != 1) return;
    call_out("comer_victima", 1 + random(5), quien);
}

public void heart_beat()
{
    ::heart_beat();
    if (tiempo > TIEMPO_RED_FOOD)
    {
        AddFood(-1);
        tiempo = 0;
    }
    else tiempo = tiempo + 2;
}
