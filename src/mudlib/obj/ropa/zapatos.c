/*unos zapatos, parte del equipo b�sipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_GENERIC, M_CUERO);
SetShort("unos zapatos");
SetLong(
"Son unos zapatos de cuero sin te�ir, con cordones del mismo material y una suela hecha "
"de cuatro l�minas superpuestas para proteger la planta del pie.\n"
"Es un calzado simple pero funcional, apto para cualquier latitud.\n");
SetIds(({"zapatos","ropa", "zapatos de cuero"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_PLURAL);

}