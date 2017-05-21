/* [Woo] Modificado */
#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>

inherit KBASE;

create() {
  ::create();
  SetStandard("un enano paseante","enano",3,GENDER_MALE);
  SetShort("un enano paseando");
  SetLong(
"Es un enano normal sin uniforme ni nada que indique una posicion.\n"
"Tiene la mirada perdida en los detalles del lugar, no te presta\n"
"atencion\n");
  SetIds(({"paseante","enano"}));
  SetAds(({"enano","un"}));
  SetAlign(0);
  SetAC(3);
  SetGoChance(50);
InitChats(10,({
    "El enano murmura para si mismo: Bonito lugar.\n",
    "El enano dice: Cada vez que paso me gusta más esto.\n",
    "El enano dice: A ver si saco un poco de mithril.\n"}) );
  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "ropa enana",
      P_LONG:  "Ropas pequeñas de enano pero resistentes.\n",
      P_IDS: ({"ropa"}),
      P_ADS: ({"enana","resistente"}),
      P_ARMOUR_TYPE:AT_ARMOUR,
      P_AC: 1,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 99,
      P_WEIGHT: 400,
      P_VALUE: 100]) );
}


move(dest,method,stuff) // No puede salir de Kha-annu
{
 if(method==M_GO && dest->QueryLocate()!="Kha-annu")
    return ME_NO_ENTER;
        return ::move(dest,method,stuff);
}


