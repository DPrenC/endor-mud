/****************************************************************************
Fichero: /d/akallab/comun/objeto/bebida/tinaja.c
Autor: Lug y Yalin
Fecha: 08/05/2007
Descripci�n: Tinaja para la casa de los trolls de Kunz.
****************************************************************************/

#include <properties.h>
#include <drink.h>
inherit "/obj/fountain";

create(){
    ::create();
    SetGender(GENDER_FEMALE);
    SetShort("una tinaja de barro");
    SetLong("Es una vasija hecha de barro cocido, m�s ancha por el centro "
        "que en su base y en el borde.\nNormalmente se usa para almacenar "
        "agua en las casas.\n");
    AddId(({"tinaja"}));
    SetCapacity(50000);
    SetFull(45000);
    SetSeeState(1);
    SetDrinkMsg(({"Te inclinas sobre la tinaja, y aunque moj�ndote la cara, "
        "consigues beber un sorbo de agua\n",
    "Se inclina sobre la tinaja y bebe un trago de agua, aunque moj�ndose "
        "bastante la cara.\n"}));
    SetCantDrinkMsg(({"Te inclinas sobre la tinaja con la intenci�n de beber "
        "un poco de agua, pero no puedes tragar ni una gota m�s, as� que "
        "desistes ante el peligro de reventar.\n",
        "Se inclina sobre la tinaja, pero no es capaz de beber ni una gota m�s.\n"}));
    SetNoWaterMsg(({"Te inclinas sobre la tinaja con la intenci�n de beber "
        "agua, pero la tinaja est� vac�a, as� que, con gesto decepcionado, "
        "vuelves a levantarte.\n",
        "Se inclina sobre la tinaja intentando beber agua, pero encuentra la "
        "tinaja vac�a, y se yergue con cara de disgusto.\n"}));
    SetCommandsDrink(({"agua","agua de tinaja","agua de la tinaja","de la tinaja",
        "de tinaja"}));
    SetNoGet("No hagas tonter�as. Si rompes la tinaja, los trolls que viven "
        "en la casa te romper�n la cabeza.\n");
}
