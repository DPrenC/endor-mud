/*unas mu�equeras de cuero, parte del equipo b�sico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PULSERA, 0, P_SIZE_GENERIC, M_CUERO);
    SetShort("unas mu�equeras de cuero");
SetLong(
"Se trata de unas anchas bandas de cuero curtido sin te�ir que se ajustan a la mu�eca y "
"la protegen de golpes y magulladuras, fortaleci�ndola tambi�n en el manejo de armas y "
"herramientas pesadas.\n");
SetIds(({"mu�equera","ropa", "mu�equeras de cuero", "cuero", "mu�equeras"}));
SetAds(({"de", "cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_FEMALE);
}