/***
fichero: encubierto.c
Autor: kastwey@simauria
Descripción: Guardia encubierto para el puesto de guardia de siempreunidos.
Creación: 30/11/2004
***/
#include "path.h"
#include <gremios.h>
inherit STD_FAERIA("guardia_base_faeria");


create()
{
    ::create();
   SetStandard("un elfo", "elfo", ([GC_GUARDABOSQUE:30+random(5)]), 1);
    SetShort("un elfo");
    SetLong("Es un elfo alto. Te observa con una mirada penetrante.\n");
    SetLongDesprecio(W("Es un elfo alto. Te observa con una mirada penetrante.\n"
        "Si las miradas matasen, ya llevarías muert" + AO + " un buen rato.\n"));
}


public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    // si tiene menos del 50% de vida, y tambien teniendo en cuenta
    // un random (no pide ayuda siempre) y que no haya un refuerzo pedido por él,
    // pide ayuda a un refuerzo.
    if (pPedirRefuerzos && !pRefuerzo && QueryHealth() < 50 && !random(4))
    {
        int i;
        if (TP->QueryGuildLevel() < 40) pRefuerzo = clone_object(PNJ_PUESTO("sargento"));
        else pRefuerzo = clone_object(PNJ_PUESTO("conjurador"));
        pRefuerzo->SetPedirRefuerzos(0);
        pRefuerzo->move(environment());
        pRefuerzo->AddEnemies(QueryEnemies());
        if (QueryKiller()) TABLON_ENEMIGOS->AddEnemy(QueryKiller());
        tell_room(environment(TO), W("El elfo grita pidiendo ayuda!\n"
            "Al instante, aparece " + lower_case(pRefuerzo->QueryName()) + " para socorrer a su compañero.\n"));
    }
    return ::DoDamage (damage, type, gentle, &xtras);
}
