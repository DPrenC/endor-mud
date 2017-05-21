/* Espada corta
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_ESPADA, 6, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una espada corta");
  SetLong(W("Es una espada corta de hierro de una mano. El mango también es "
  	"de metal, pero tiene una cinta de cuero rodeándolo para hacer más "
  	"cómodo el agarre.\n"));
  SetIds(({"espada", "espada corta"}));
  Set(P_GENDER, GENDER_FEMALE);
}