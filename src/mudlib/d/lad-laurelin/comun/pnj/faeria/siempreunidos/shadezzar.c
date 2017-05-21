#include "path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit STD_FAERIA("guardia_conjurador_faeria");



create()
{
    ::create();
   seteuid(getuid());
    SetStandard("Shadezzar", "elfo", ([GC_CONJURADOR: 70+random(10)]), GENDER_MALE);
    SetShort("Shadezzar");
    SetLong(W("Ves a un elfo alto y fuerte.\n"
    "Parece un elfo más viejo que el resto de los elfos que has podido ver por Simauria. Su cabellera es escasa, y luce una poblada barba que le da aspecto de bonachón.\n"));
    SetLongDesprecio(QueryLong() + "Te observa con una mirada suspicaz y alerta. Por su expresión dirías que no se alegra demasiado de que andes por su casa.\n");
    SetSpellChance(700);
    AddId("guardian_siempreunidos");
    SetStr(QueryStr() + 10);
    SetDex(QueryDex() + 10);
    AddItem("/obj/armas/vara", REFRESH_REMOVE,
        ([
            P_SHORT: "un cayado",
            P_IDS: ({"cayado", "vara"}),
            P_GENDER: GENERO_MASCULINO,
            P_LONG: W("Es un cayado blanco de madera. En toda su superficie, ves grabados unos símbolos que eres incapaz de descifrar.\n"
                "Parece algo más que un cayado, aunque al menos como arma, seguro que es efectivo para golpear.\n")
        ]), SF(wieldme));
    AddItem("/std/armour", REFRESH_REMOVE,
        ([
            P_SHORT :"una túnica verde",
            P_LONG: W("Es una túnica verde. A pesar de su apariencia delicada, no te cabe la menor duda de que su tela es resistente como la que más.\n"
                "Lleva bordada el escudo de un unicornio dorado.\n"),
            P_MATERIAL: M_TELA,
            P_AC: 5,
            P_SIZE: P_SIZE_MEDIUM,
            P_VALUE: 2000,
            P_ARMOUR_TYPE: AT_TUNICA,
            P_GENDER: GENERO_FEMENINO,
            P_IDS: ({"túnica", "tunica", "capa"})
        ]), SF(wearme));
}



public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    // si tiene menos del 50% de vida, y tambien teniendo en cuenta
    // un random (no pide ayuda siempre)
    // pide ayuda a un pRefuerzo.
    if (pPedirRefuerzos && !pRefuerzo && QueryHealth() < 50 && !random(4))
    {
        pRefuerzo = clone_object(PNJ_PUESTO("conjurador"));
        pRefuerzo->SetPedirRefuerzos(0);
        tell_room(environment(TO), W("El conjurador grita pidiendo ayuda!\n"
            "Al instante, aparece " + lower_case(pRefuerzo->QueryName()) + " para socorrer a su compañero.\n"));
        pRefuerzo->move(environment());
        pRefuerzo->AddEnemies(QueryEnemies());
        // if (QueryKiller()) TABLON_ENEMIGOS->AddEnemy(QueryKiller());
    }
    return ::DoDamage (damage, type, gentle, &xtras);
}
