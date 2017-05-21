/* Fichero: piedra_afilar.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: una piedra para afilar las armas con filo.
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
  "Es una lasca de porosa piedra pómez, plana y de forma más o menos romboidal. Pese a "
  "que puede ser quebradiza, es muy útil para pulir y afilar las hojas de armas y "
  "herramientas por la abrasión de los diminutos granos que se van soltando de la piedra "
  "cuando esta se frota contra un metal.\n");
  }