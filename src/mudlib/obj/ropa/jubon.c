/* un jubón, parte del equipo básico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TABARDO, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("un jubón");
SetLong(
".\n");
SetIds(({"jubon","ropa", "jubón"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}