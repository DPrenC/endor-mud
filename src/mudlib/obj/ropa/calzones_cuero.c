/*Unos calzones cortos de cuero, parte del equipo b�sico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("unos calzones de cuero blando");
SetLong(
"Son unos pantalones largos confeccionados con vasta tela sin te�ir.\n"
"Llegan hasta el tobillo y cuentan con un bolsillo grande a cada lado.\n"
"Prenda t�picamente masculina, suele utilizarse por muchas culturas en muchas "
"latitudes.\n");
SetIds(({"calzones","ropa", "calzon", "calz�n", "calzones de cuero", "cuero"}));
SetAds(({"cortos","vastos", "curtidos", "blando", "de cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_MALE);
}