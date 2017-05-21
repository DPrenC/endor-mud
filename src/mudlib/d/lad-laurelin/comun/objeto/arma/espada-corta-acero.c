/* Espada corta de acero
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
 SetStandard(WT_ESPADA, 7, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una espada corta de acero");
  SetLong(W("Es una espada corta de aleación de acero y de hierro de una "
  	"sola mano. El mango también es "
  	"de metal, pero tiene una cinta de cuero rodeándolo para hacer más "
  	"cómodo el agarre.\n"));
  SetIds(({"espada", "espada corta"}));
  Set(P_GENDER, GENDER_FEMALE);
}