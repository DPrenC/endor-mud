/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*  [a] Articman                                                          */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y a�adidos los W()     */
/*  [a] 3/5/2002            Castellanizaci�n y retoques                   */
/**************************************************************************/

#include <combat.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create ()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("el interior de una caba�a");
    SetIntLong("Esta caba�a es vieja, pero parece bien construida. Por doquier, se "
    "advierten �tiles de labranza y peque�os utensilios, �tiles para sembrar "
    "campos y cultivar hortalizas. En estos momentos, el propietario de la "
    "casa no se encuentra en ella, pero sus cosas est�n aqu�, dispuestas por "
    "si alguien quiere echar una mano a un pobre labriego.\n");
    SetIntBright(20);
    AddItem("/std/weapon",REFRESH_REMOVE,2,
      ([P_SHORT: "azada",
        P_LONG: "Es una azada, hecha para trabajos en el campo.\n",
        P_IDS: ({"azada","aza","az�"}),
        P_WC:5,
        P_NUMBER_HANDS:2,
        P_SIZE:P_SIZE_GENERIC,
        P_RESET_QUALITY: 100,
        P_WEIGHT: 2500,
        P_VALUE:  90,
        P_WEAPON_TYPE: WT_HACHA,
        P_DAM_TYPE: DT_SLASH]) );
    AddExit("oeste","../calle6" );
    AddDoor("oeste");
}