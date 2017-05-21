/*
DESCRIPCION : fonda en el cruce del camino del Este
FICHERO     : /d/akallab/comun/habitacion/azzor/camino/fonda.c
MODIFICACION: 24-02-99 [Angor@Simauria] Creacion
                       [woo] Modificada para que use el estandar
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO

inherit PUB;

create()
{
    ::create();
    SetIntShort("la fonda Cráneo de Elfo");
    SetIntLong("Acabas de entrar en la fonda Cráneo de Elfo, un lugar bastante lóbrego y "
        "oscuro. Las comidas aquí no es que sean muy recomendables pero cuando se trata de "
        "saciar el hambre o la sed cualquier sitio vale.\n");
    SetIntBright(25);
    SetLocate("valle de Azzor");
    SetKeeper(PNJ_AZZOR("walij"));
    SetCloseTime(({}));
    SetNotifyExits(({}));
    AddExit("este",AZ_CAMINO("camino06"));
    AddExit("sur",AZ_CAMINO("camino05"));

    AddFood("jabali asado","un plato de",8,10,0);
    AddFood("cordero al horno","un plato de",9,9,0);
    AddFood("truchas asadas","un par de",7,8,0);
    AddFood("caldo de verduras","un cuenco de",5,6,0);
    AddDrink("vino","un vaso de",4,6,6,0);
    AddDrink("cerveza","una jarra de",6,6,6,0);
}
