/*un cintur�n, parte del equipo b�sipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_CINTURON, 0, P_SIZE_GENERIC, M_CUERO);
SetShort("un cintur�n de cuero");
SetLong(
"Es un sencillo cintur�n de cuero curtido y sin te�ir, con una hebilla de bronce y una "
"serie de orificios para ajustarlo en torno a las caderas de su portador.\n"
"Suele utilizarse para sujetar los pantalones o calzones y  portar vainas de "
"armas o peque�as bolsas con lo indispensable.\n");
SetIds(({"cintur�n","ropa", "cinturon de cuero", "cinturon"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}