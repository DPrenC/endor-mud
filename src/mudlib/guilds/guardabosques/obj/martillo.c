/* Martillo de guerra, dos manos
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_MAZA, 14, P_SIZE_MEDIUM, M_HIERRO);
  Set(P_GENDER, GENDER_MALE);
  SetShort("un martillo de guerra");
  SetLong(W("Es un martillo de guerra de dos manos. La enorme cabeza de metal "
  	"está unida a un larguísimo mango tembién metálico.\n"));
  SetIds(({"martillo", "martillo de guerra"}));
}