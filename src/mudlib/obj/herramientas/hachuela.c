/* fichero: hachuela.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: una hachuela para podar ramas, trabajar madera, afilar cosas de madera....*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_HACHA, 2,P_SIZE_GENERIC,M_HIERRO);
 SetShort("una hachuela");
 SetLong(
 "Es una pequeña hacha con un mango de unos 40 centímetros de longitud y una hoja "
 "triangular que se ensancha desde el mango hacia el filo. Es muy sencilla y útil "
 "para desgajar ramas, descuartizar algún animal o como arma secundaria o arrojadiza.\n");
 AddId(({"hachuela", "herramienta"}));
AddAdjective(({"hacha", "de", "mano", "sencilla", "ligera"}));
SetWeight(1500);

}