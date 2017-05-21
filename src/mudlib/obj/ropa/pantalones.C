/*Unos pantalones, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("unos pantalones");
SetLong(
"Son unos pantalones largos confeccionados con vasta tela sin teñir.\n"
"Llegan hasta el tobillo y cuentan con un bolsillo grande a cada lado.\n"
"Prenda típicamente masculina, suele utilizarse por muchas culturas en muchas "
"latitudes.\n");
SetIds(({"pantalones","ropa", "pantalon", "pantalón"}));
SetAds(({"largos","vastos"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_MALE);
}