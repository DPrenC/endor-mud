/***
fichero: soldado.c
Autor: kastwey@simauria
Descripción: Soldado para el puesto de guardia de siempreunidos.
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
   SetStandard("un soldado", "elfo", ([GC_GUARDABOSQUE:20+random(5)]), 1);
    SetShort("un soldado");
    SetLong("Ves un elfo alto y apuesto. Lleva armadura de cuero con una insignia de un unicornio dorado, espada y arco. Parece estar atento a todo lo que pasa a su alrededor.\n");
    AddId("soldado");
    AddItem("/obj/arco", REFRESH_REMOVE,
        ([
            P_LONG: W("Es un arco hecho de una madera muy flexible.\n"
                "En una persona con buen pulso, mirada certera y manos hábiles, no te cabe la menor duda de que es un arma temible.\n"),
        ]));
    AddItem("/obj/armas/espada_ancha", REFRESH_REMOVE, SF(wieldme), 1);
    AddItem("/obj/carcaj", REFRESH_REMOVE, 1);
    AddItem("/std/armour", REFRESH_REMOVE,
        ([
            P_SHORT: "una armadura",
            P_LONG: "Es una resistente armadura de cuero. Lleva la insignia de un unicornio dorado.\n",
            P_GENDER: GENERO_FEMENINO,
            P_ARMOUR_TYPE: AT_CORAZA,
            P_AC: 10,
            P_MATERIAL: M_CUERO,
            P_SIZE: P_SIZE_MEDIUM,
        ]), SF(wearme));
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    // si tiene menos del 50% de vida, y tambien teniendo en cuenta
    // un random (no pide ayuda siempre)
    // pide ayuda a un refuerzo, teniendo en cuenta que no haya un refuerzo
    // llamado por él.
    if (pPedirRefuerzos && !pRefuerzo && QueryHealth() < 50 && !random(4))
    {
        switch(TP->QueryGuildLevel())
        {
            case 1..9:
                break;
            case 10..29:
            // aquí se elige el tipo de porcentaje:
                switch(random(100))
                {
                // Si el oponente es de nivel 10 a 30 10% que no aparezca nadie, 60%
                // que aparezca un soldado, 20% que aparezca un sargento y 10% que aparezca un conjurador.
                    case 0..9:
                    // nadie:
                        break;
                    case 10..69:
                    // soldado:
                        pRefuerzo = clone_object(PNJ_PUESTO("soldado"));
                        break;
                    case 70..89:
                    // sargento
                        pRefuerzo = clone_object(PNJ_PUESTO("sargento"));
                        break;
                    case 90..99:
                    // un conjurador
                    // si a un player de nivel 10 le sale un conjurata, ya se puede ir dando
                    // casi por muerto... :(((((( ;)
                        pRefuerzo = clone_object(PNJ_PUESTO("conjurador"));
                        break;
                }
                // si hay pRefuerzo, este no pedirá ayuda
                if (pRefuerzo)pRefuerzo->SetPedirRefuerzos(0);
                break;
            case 30..40:
            // aqui sale un sargento.
                if (!random(4))
                {
                    pRefuerzo = clone_object(PNJ_PUESTO("sargento"));
                    pRefuerzo->SetPedirRefuerzos(0);
                }
                break;
            default:
            // es un nivel alto, asín que un conjurata.
                pRefuerzo = clone_object(PNJ_PUESTO("conjurador"));
                pRefuerzo->SetPedirRefuerzos(0);
                break;
        }
        // si hay pRefuerzo, se mueve a la room y se avisa
        if (pRefuerzo)
        {
            tell_room(environment(TO), W("El soldado grita pidiendo ayuda!\n"
            "Al instante, aparece " + lower_case(pRefuerzo->QueryName()) + " para socorrer a su compañero.\n"));
            pRefuerzo->move(environment());
            pRefuerzo->AddEnemies(QueryEnemies());
            if (QueryKiller()) TABLON_ENEMIGOS->AddEnemy(QueryKiller());
        }
    }
    return ::DoDamage (damage, type, gentle, &xtras);
}
