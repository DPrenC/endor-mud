/****************************************************************************
Fichero: /d/akallab/comun/objeto/bebida/tinaja.c
Autor: Lug y Yalin
Fecha: 08/05/2007
Descripción: Tinaja para la casa de los trolls de Kunz.
****************************************************************************/

#include <properties.h>
#include <drink.h>
inherit "/obj/fountain";

create(){
    ::create();
    SetGender(GENDER_FEMALE);
    SetShort("una tinaja de barro");
    SetLong("Es una vasija hecha de barro cocido, más ancha por el centro "
        "que en su base y en el borde.\nNormalmente se usa para almacenar "
        "agua en las casas.\n");
    AddId(({"tinaja"}));
    SetCapacity(50000);
    SetFull(45000);
    SetSeeState(1);
    SetDrinkMsg(({"Te inclinas sobre la tinaja, y aunque mojándote la cara, "
        "consigues beber un sorbo de agua\n",
    "Se inclina sobre la tinaja y bebe un trago de agua, aunque mojándose "
        "bastante la cara.\n"}));
    SetCantDrinkMsg(({"Te inclinas sobre la tinaja con la intención de beber "
        "un poco de agua, pero no puedes tragar ni una gota más, así que "
        "desistes ante el peligro de reventar.\n",
        "Se inclina sobre la tinaja, pero no es capaz de beber ni una gota más.\n"}));
    SetNoWaterMsg(({"Te inclinas sobre la tinaja con la intención de beber "
        "agua, pero la tinaja está vacía, así que, con gesto decepcionado, "
        "vuelves a levantarte.\n",
        "Se inclina sobre la tinaja intentando beber agua, pero encuentra la "
        "tinaja vacía, y se yergue con cara de disgusto.\n"}));
    SetCommandsDrink(({"agua","agua de tinaja","agua de la tinaja","de la tinaja",
        "de tinaja"}));
    SetNoGet("No hagas tonterías. Si rompes la tinaja, los trolls que viven "
        "en la casa te romperán la cabeza.\n");
}
