/* Guada�a de combate, dos manos
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
 SetStandard(WT_HACHA, 12, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una guada�a de dos manos");
  SetLong(W("Es una enorme guada�a de dos manos de las que usan los campesinos "
  	"para la recolecci�n de grano. Sin embargo esta est� confeccionada "
  	"para ser usada como arma, ya que la agarradera superior est� "
  	"remachada con cuero, lo que evita que las astillas de la madera se "
  	"claven en la mano del que la empu�a.\n"));
  SetIds(({"guada�a", "guada�a de combate", "guada�a de dos manos",
  	"guadanya", "guadanya de combate", "guadanya de dos manos"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER_HANDS, 2);
}