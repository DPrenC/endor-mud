/* FICHERO: hacha_lenyador.C
Autor: Aulë
Fecha: 13/09/2014
Descripción: hacha para talar y habilidades derivadas.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_HACHA_PESADA, 6, P_SIZE_LARGE, M_HIERRO);
  SetShort("un hacha de LEÑADOR");
  SetLong(
"Es un hacha grande, sencilla, pesada pero muy funcional. El mango es de madera sin "
"guarnición de ningún tipo y la hoja es triangular y sencilla, perfecta para talar "
"árboles o cortar leña.\n");
AddId(({"hacha_leñador", "herramienta"}));
    AddAdjective(({"de","leñador","lenyador"}));

}