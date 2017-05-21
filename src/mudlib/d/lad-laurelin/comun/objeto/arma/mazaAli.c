/* Maza de combate, una mano
   Alura
   arma especial
*/

inherit WEAPON;
#include "path.h"
#include <combat.h>
#include <materials.h>
#include <properties.h>

create()
{
  ::create();
  if (!clonep()) return;
  SetStandard(WT_MAZA, 5, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una maza de combate sagrada");
  SetLong(W("Es una maza de combate de una mano. Está compuesta por una "
  	"cabeza de oro alargada y cilíndrica, con muchas púas de "
  	"considerable tamaño. Tiene tallados unas marcas que te incitan a"
	"pensar que es un arma bendecida por los dioses.\n"));
  SetIds(({"maza", "maza de combate sagrada"}));
  Set(P_GENDER, GENDER_FEMALE);
  SetValue(30000000);
}

public varargs void NotifyEquip(object liv, object weapon, int flags)
{
  if (weapon != TO) return;
	if (liv->QueryAlign()>0){
 		weapon->SetWC(9);
		tell_object(TP,"La maza vibra en tus manos.\n");
	} else {
		weapon->SetWC(5);
		tell_object(TP,"La maza se ennegrece al contacto con tus malvadas manos.\n");
	}
	::NotifyEquip(liv, weapon, flags);
}
