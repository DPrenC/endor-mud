/* un jub�n de cuero, parte del equipo b�sico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TABARDO, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("un jub�n de cuero blando");
SetLong(
".\n");
SetIds(({"jubon","ropa", "jub�n"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}