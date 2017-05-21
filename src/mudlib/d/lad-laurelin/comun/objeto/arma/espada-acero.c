/* Espada de dos manos
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
 SetStandard(WT_ESPADA, 9, P_SIZE_MEDIUM, M_ACERO);
  SetShort("una espada larga de acero");
  SetLong(W("Es una espada larga de combate hecha con una "
  	"aleación de acero rígido y de hierro más maleable. El resultado es "
  	"una magnífica espada de combate.\n"));
  AddId("espada");
  Set(P_NUMBER_HANDS, 1);
  Set(P_GENDER, GENDER_FEMALE);
}