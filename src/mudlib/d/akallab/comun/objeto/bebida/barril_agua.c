/****************************************************************************
Fichero: barril.c
Autor: Buh
Fecha: 29/11/2006
Descripción: un barril para beber y provar fountain.c
****************************************************************************/

#include <properties.h>
inherit "/obj/fountain";

create(){
    ::create();
    AddId(({"barril","tonel"}));
    SetShort("un barril");
    SetLong("Un enorme barril, abierto por arriba, que  casi siempre contiene agua "
        "fresca.\n");
    SetCapacity(100000);
    SetFull(90000);
    SetDrinkPointsPerDraught(10);
    SetSeeState(1);
    SetDrinkMsg(({"metes la cabeza dentro del barril y bebes agua mojandote la cara.\n",
        "mete la cabeza dentro del barril y se pone a beber agua mojándose la cara por"
        " completo.\n"}));
    SetCantDrinkMsg(({"metes la cabeza en el barril para beber agua, pero ya no te cabe"
        " ni una gota más y desistes de seguir bebiendo.\n", "mete la cabeza en el barril"
        " con intención de beber agua, pero parece que se lo piensa mejor y vuelve a "
        "sacarla.\n"}));
    SetNoWaterMsg(({"metes la cabeza en el barril para beber agua, pero te das cuenta "
        "que ya no queda ni una gota, así que vuelves a sacarla con resignación.\n",
        "mete la cabeza en el barril pero, tras darse cuenta que está vacío, vuelve a "
        "sacarla con la cara consternada.\n"}));
    SetCommandsDrink(({"agua","agua de barril","agua del barril","del barril",
        "de barril"}));
    SetGender(GENDER_MALE);
    SetNoGet("El barril es demasiado grande y pesado para que puedas cogerlo.\n");
}
