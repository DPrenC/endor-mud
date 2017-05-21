/* fichero: hacha_mano.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_HACHA,4,P_SIZE_GENERIC,M_HIERRO);
 SetShort("un hacha de mano");
 SetLong(
 "Es una pequeña hacha con un mango de unos 40 centímetros de longitud y una hoja "
 "triangular que se ensancha desde el mango hacia el filo. Es muy sencilla y útil "
 "para desgajar ramas, descuartizar algún animal o como arma secundaria o arrojadiza.\n");

SetAds(({"arma", "hacha", "de", "mano", "sencilla", "ligera"}));
SetWeight(1500);

}