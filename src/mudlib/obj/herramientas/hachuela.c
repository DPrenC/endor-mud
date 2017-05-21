/* fichero: hachuela.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: una hachuela para podar ramas, trabajar madera, afilar cosas de madera....*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_HACHA, 2,P_SIZE_GENERIC,M_HIERRO);
 SetShort("una hachuela");
 SetLong(
 "Es una peque�a hacha con un mango de unos 40 cent�metros de longitud y una hoja "
 "triangular que se ensancha desde el mango hacia el filo. Es muy sencilla y �til "
 "para desgajar ramas, descuartizar alg�n animal o como arma secundaria o arrojadiza.\n");
 AddId(({"hachuela", "herramienta"}));
AddAdjective(({"hacha", "de", "mano", "sencilla", "ligera"}));
SetWeight(1500);

}