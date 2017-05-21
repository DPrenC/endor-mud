#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit NPC;
create() {
  ::create();
 SetStandard("ladr�n humano","humano",4,GENDER_MALE);
SetShort("Un ladron humano");
  SetLong(
"Es un pobre ladr�n cansado y agobiado de la celda.\n"
"Tiene las ropas desgarradas y est� muy sucio.\n");
  SetIds(({"ladron","humano"}));
  SetAds(({"ladron","un"}));
  SetAlign(0);
  InitChats(3,({
    "El ladr�n dice: Sacadme de aqui, yo solo paseaba por el monte.\n",
    "El ladr�n dice: parece que los enanos se olvidaron de mi.\n"} ) );
  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "ropa oscura",
      P_LONG: "La ropa est� algo desgarrada.\n",
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
