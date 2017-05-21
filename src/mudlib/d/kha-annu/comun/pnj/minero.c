/* Creado por Gorthem para la ciudad de Kha-annu */
/* Retocado por [Y] Yandros a 29.01.99 */
#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>
inherit KBASE;

create() {
  ::create();
  SetStandard("un minero enano","enano",4,GENDER_MALE);
  SetShort("un enano minero");
  SetLong(
"Es un pobre enano que parece haber 'abusado' demasiado de su trabajo. Tiene\n"
"las ropas gastadas y llenas de polvo, y sus manos están llenas de callos.\n");
  SetIds(({"minero","enano","trabajador"}));
  SetAds(({"enano","un"}));
  SetAlign(0);
  SetAC(4);
  SetGoChance(60);
InitChats(10,({
    "El enano dice: Ahí voy, a la mina a trabajar.\n",
    "El enano dice: ¿Dónde está tu pico?\n",
    "El enano dice: A ver si saco un poco de mithril.\n"}) );
  AddItem("/obj/money",REFRESH_REMOVE,
  (["Money": (["oro":random(10) ]) ]) );
  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "casco minero",
      P_LONG:  "Parece muy gastado y sucio.\n",
      P_IDS: ({"casco"}),
      P_ADS: ({"gastado","sucio","un"}),
      P_ARMOUR_TYPE:AT_HELMET,
      P_AC: 1,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 81,
      P_WEIGHT: 500,
      P_VALUE: 4]) );
  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "un par de guantes",
      P_LONG:  "Los guantes están tan desagastados que tienen agujeros.\n",
      P_IDS: ({"guantes"}),
      P_ADS: ({"un","par de","desgastados"}),
      P_WEIGHT: 150,
      P_VALUE: 1,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 55,
     P_AC: 0,
      P_ARMOUR_TYPE:AT_GLOVES]) );
}

move(dest,method,stuff) // No puede salir de Kha-annu
{
 if(method==M_GO && dest->QueryLocate()!="Kha-annu")
    return ME_NO_ENTER;
        return ::move(dest,method,stuff);
        }



