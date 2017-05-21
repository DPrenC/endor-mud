/*una cinta de cuero para sujetar el pelo, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TIARA, 0, P_SIZE_GENERIC, M_CUERO);
    SetShort("una cinta de cuero blando");
SetLong(
"Es una sencilla cinta de cuero, blando y sin teñir que se utiliza para sujetar el pelo.\n");
SetIds(({"cinta","ropa", "cinta de cuero", "cuero"}));
SetAds(({"blanda", "de", "cuero"}));
Set(P_NUMBER,NUMBER_SINGULAR);
Set(P_GENDER,GENDER_FEMALE);
}