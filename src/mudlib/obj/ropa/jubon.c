/* un jub�n, parte del equipo b�sico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TABARDO, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("un jub�n");
SetLong(
".\n");
SetIds(({"jubon","ropa", "jub�n"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}