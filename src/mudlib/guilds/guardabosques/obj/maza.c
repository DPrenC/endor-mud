/* Maza de combate, una mano
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_MAZA, 8, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una maza de combate");
  SetLong(W("Es una maza de combate de una mano. Est� compuesta por una "
  	"cabeza de metal alargada y cil�ndrica, con muchas p�as de "
  	"considerable tama�o.\n"));
  SetIds(({"maza", "maza de combate"}));
  Set(P_GENDER, GENDER_FEMALE);
}