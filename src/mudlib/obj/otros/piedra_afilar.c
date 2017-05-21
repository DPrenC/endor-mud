/* Fichero: piedra_afilar.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: una piedra para afilar las armas con filo.
*/

#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(150);
  SetWeight(150);
  SetIds(({"piedra","piedra de afilar"}));

  SetShort("una piedra de afilar");
  SetLong(
  "Es una lasca de porosa piedra p�mez, plana y de forma m�s o menos romboidal. Pese a "
  "que puede ser quebradiza, es muy �til para pulir y afilar las hojas de armas y "
  "herramientas por la abrasi�n de los diminutos granos que se van soltando de la piedra "
  "cuando esta se frota contra un metal.\n");
  }