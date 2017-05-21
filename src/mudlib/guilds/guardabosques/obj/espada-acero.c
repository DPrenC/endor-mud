/* Espada de dos manos
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_ESPADA, 9, P_SIZE_MEDIUM, M_ACERO);
  SetShort("una espada larga de acero");
  SetLong(W("Es una espada larga de combate hecha con una "
  	"aleaci�n de acero r�gido y de hierro m�s maleable. El resultado es "
  	"una magn�fica espada de combate.\n"));
  AddId("espada");
  Set(P_WEAPON_HANDS, 1);
  Set(P_GENDER, GENDER_FEMALE);
}