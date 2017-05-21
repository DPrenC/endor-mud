/*   misericordia.c
     Creado por : Nemesis
     Fecha: 30-Jul-01
	 Descripci�n: Arma secundaria de los guardias que lleven dos armas.
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_CUCHILLO, 2, P_SIZE_GENERIC, M_ACERO);
  SetAds(({"una","puntiaguda"}));
  SetIds(({"misericordia","arma","pu�al"}));
  SetShort("una misericordia");
  SetLong("Un pu�al de hoja larga y muy fina, con una aguda punta.\n");
  SetValue(random(3)); // baratilla, pa que no los jugatas no se pasen...
  SetDamType(DT_PIERCE);
  Set(P_GENDER,GENDER_FEMALE);
}
