/*Un faldón de cuero, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("un faldón de cuero");
SetLong(
"Es un faldón de cuero sin teñir, curtido pero flexible, que cubre las piernas hasta "
"media pantorrilla y posee unas largas aberturas en la parte anterior y posterior para "
"permitir una mayor libertad de movimientos a las piernas, tanto a pie como a caballo.\n"
"Prenda útil para protegerse del frío, el calor, los roces o  rasguños de todo tipo, "
"suele ser utilizada más por guerreros, batidores o aventureros.\n");
SetIds(({"faldon","ropa", "faldón"}));
SetAds(({"largo","vasto", "curtido", "de cuero"}));
Set(P_NUMBER,NUMBER_SINGULAR);
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_PLURAL);

}