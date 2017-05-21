/*unas grebas de cuero, parte del equipo b�sico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_GREBAS, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("unas grebas de cuero");
SetLong(
"Son unas grebas de cuero blando, flexible y sin te�ir, formadas por secciones "
"rectangulares de cuero que se ajustan a los muslos mediante una serie de finas correas "
"y hebillas met�licas, guarneciendo la parte alta de la pierna hasta la rodilla y el "
"interior de los muslos.\n"
"Protegen livianamente las piernas contra rasgu�os, cortes o contusiones ligeras.\n");
SetIds(({"grebas","ropa", "grebas de cuero", "cuero", "greba"}));
SetAds(({"de", "cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_FEMALE);
}