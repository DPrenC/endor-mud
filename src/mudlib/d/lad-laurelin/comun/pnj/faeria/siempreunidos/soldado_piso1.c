/***
Fichero: soldado_piso1.c
Autor: kastwey@simauria
Descripción: Soldado para el dormitorio de los guardias.
Creación: 06/12/2004
***/
#include "path.h"
#include <moving.h>

inherit PNJ_PUESTO("soldado");
int pLlamados;
// si ya han llegado los guardias de las otras salas, no
// se vuelven a llamar más en cada DoDamage.

create()
{
    ::create();
    SetAggressive(1);
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    object *guardias;
    int i;
    if (pLlamados) return ::DoDamage(damage, type, gentle, &xtras);
    else
    {
        guardias = all_inventory(to_object(environment()->QueryExits()["este"])) || ({});
        guardias += all_inventory(to_object(environment()->QueryExits()["oeste"])) || ({});
        guardias = filter(guardias, (: call_other($1, "QueryIsGuardia") :) );

        // debug tell_object(find_object("kastwey"), to_string(sizeof(guardias)) + "\n");
        for (i=sizeof(guardias);i--;)
        {
            tell_room(environment(TO), W(guardias[i]->QueryName() + " llega corriendo.\n"));
            tell_room(environment(guardias[i]), TO->QueryName() + " sale corriendo hacia el dormitorio.\n");
            guardias[i]->move(environment(TO), M_SILENT);
        }
        pLlamados = 1;
        // ya no se vuelve a hacer más en el DoDamage.
        return ::DoDamage(damage, type, gentle, &xtras);
    }
}


public void reset()
{
    ::reset();
    pLlamados = 0;
}

