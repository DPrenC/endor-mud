/*Un fald�n de cuero, parte del equipo b�sico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("un fald�n de cuero");
SetLong(
"Es un fald�n de cuero sin te�ir, curtido pero flexible, que cubre las piernas hasta "
"media pantorrilla y posee unas largas aberturas en la parte anterior y posterior para "
"permitir una mayor libertad de movimientos a las piernas, tanto a pie como a caballo.\n"
"Prenda �til para protegerse del fr�o, el calor, los roces o  rasgu�os de todo tipo, "
"suele ser utilizada m�s por guerreros, batidores o aventureros.\n");
SetIds(({"faldon","ropa", "fald�n"}));
SetAds(({"largo","vasto", "curtido", "de cuero"}));
Set(P_NUMBER,NUMBER_SINGULAR);
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_PLURAL);

}