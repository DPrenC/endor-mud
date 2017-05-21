/* Maza de combate, una mano
   Theuzifan, 10-03-99
*/

inherit WEAPON;
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

create()
{
  ::create();
 SetStandard(WT_MAZA, 8, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una maza de combate");
  SetLong(W("Es una maza de combate de una mano. Está compuesta por una "
  	"cabeza de metal alargada y cilíndrica, con muchas púas de "
  	"considerable tamaño.\n"));
  SetIds(({"maza", "maza de combate"}));
  Set(P_GENDER, GENDER_FEMALE);
}