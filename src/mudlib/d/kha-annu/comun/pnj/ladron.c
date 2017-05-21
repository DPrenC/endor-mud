#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit NPC;
create() {
  ::create();
 SetStandard("ladrón humano","humano",4,GENDER_MALE);
SetShort("Un ladron humano");
  SetLong(
"Es un pobre ladrón cansado y agobiado de la celda.\n"
"Tiene las ropas desgarradas y está muy sucio.\n");
  SetIds(({"ladron","humano"}));
  SetAds(({"ladron","un"}));
  SetAlign(0);
  InitChats(3,({
    "El ladrón dice: Sacadme de aqui, yo solo paseaba por el monte.\n",
    "El ladrón dice: parece que los enanos se olvidaron de mi.\n"} ) );
  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "ropa oscura",
      P_LONG: "La ropa está algo desgarrada.\n",
      P_GENDER: GENDER_FEMALE,
      P_IDS: ({"ropa"}),
      P_ADS: ({"gastada","sucio"}),
      P_ARMOUR_TYPE:AT_ARMOUR,
      P_AC: 1,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 20,
      P_WEIGHT: 1000,
      P_MATERIAL:M_TELA,
      P_VALUE: 20]) );
SetGoChance(100);
}
