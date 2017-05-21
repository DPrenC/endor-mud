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
 "Es una peque�a hacha con un mango de unos 40 cent�metros de longitud y una hoja "
 "triangular que se ensancha desde el mango hacia el filo. Es muy sencilla y �til "
 "para desgajar ramas, descuartizar alg�n animal o como arma secundaria o arrojadiza.\n");

SetAds(({"arma", "hacha", "de", "mano", "sencilla", "ligera"}));
SetWeight(1500);

}