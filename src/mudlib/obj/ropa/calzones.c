/*Unos calzones, parte del equipo b�sico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("unos calzones");
SetLong(
"Son unos pantalones largos confeccionados con vasta tela sin te�ir.\n"
"Llegan hasta el tobillo y cuentan con un bolsillo grande a cada lado.\n"
"Prenda t�picamente masculina, suele utilizarse por muchas culturas en muchas "
"latitudes.\n");
SetIds(({"calzones","ropa", "calzon", "calz�n"}));
SetAds(({"largos","vastos"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_MALE);
}