/***
fichero: sargento.c
Autor: kastwey@simauria
Descripción: Sargento para el puesto de guardia de siempreunidos.
Creación: 30/11/2004
***/
#include "path.h"
#include <gremios.h>
#include <combat.h>
#include <properties.h>


inherit STD_FAERIA("guardia_base_faeria");

create()
{
    ::create();
   SetStandard("un sargento", "elfo", ([GC_GUARDABOSQUE:40+random(5)]), 1);
    SetLong(W("Este elfo lleva una armadura de cuero con dibujos en relieve de animales y árboles, la cual lleva sobre el corazón un escudo de un unicornio dorado.\n"
    "Ves que lleva dos espadas, una a cada lado del cinto. Te está observando con una mirada penetrante.\n"));
    SetLongDesprecio(QueryLong() + W("Si las miradas matasen, llevarías ya muert" + AO + " un buen rato.\n"));
    AddId("sargento");
    AddItem("/obj/armas/espada_ancha", REFRESH_REMOVE, 1, SF(wieldme));
    AddItem("/obj/armas/espada_ancha", REFRESH_REMOVE, 1, SF(wieldme));
    AddItem("/std/armour", REFRESH_REMOVE,
        ([
            P_SHORT: "una armadura",
            P_LONG: "Es una armadura de cuero. Está cubierta de dibujos de animales y árboles, y sobre el corazón luce la insignia de un unicornio dorado.\n",
            P_GENDER: GENERO_FEMENINO,
            P_AC: 10,
            P_ARMOUR_TYPE: AT_CORAZA,
            P_MATERIAL: M_CUERO,
            P_SIZE: P_SIZE_MEDIUM,
            P_VALUE: 800
        ]), SF(wearme));
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    // si tiene menos del 50% de vida, y tambien teniendo en cuenta
    // un random (no pide ayuda siempre)
    // pide ayuda a un refuerzo.
    if (pPedirRefuerzos && !pRefuerzo && QueryHealth() < 50 && !random(4))
    {
        pRefuerzo = clone_object(PNJ_PUESTO("conjurador"));
        pRefuerzo->SetPedirRefuerzos(0);
        tell_room(environment(TO), W("El sargento grita pidiendo ayuda!\n"
            "Al instante, aparece " + lower_case(pRefuerzo->QueryName()) + " para socorrer a su compañero.\n"));
        pRefuerzo->move(environment());
        pRefuerzo->AddEnemies(QueryEnemies());
        if (QueryKiller()) TABLON_ENEMIGOS->AddEnemy(QueryKiller());
    }
    return ::DoDamage (damage, type, gentle, &xtras);
}
