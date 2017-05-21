/*unas muñequeras de cuero, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PULSERA, 0, P_SIZE_GENERIC, M_CUERO);
    SetShort("unas muñequeras de cuero");
SetLong(
"Se trata de unas anchas bandas de cuero curtido sin teñir que se ajustan a la muñeca y "
"la protegen de golpes y magulladuras, fortaleciéndola también en el manejo de armas y "
"herramientas pesadas.\n");
SetIds(({"muñequera","ropa", "muñequeras de cuero", "cuero", "muñequeras"}));
SetAds(({"de", "cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_FEMALE);
}