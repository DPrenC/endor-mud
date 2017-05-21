/* FICHERO: hacha_lenyador.C
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: hacha para talar y habilidades derivadas.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_HACHA_PESADA, 6, P_SIZE_LARGE, M_HIERRO);
  SetShort("un hacha de LE�ADOR");
  SetLong(
"Es un hacha grande, sencilla, pesada pero muy funcional. El mango es de madera sin "
"guarnici�n de ning�n tipo y la hoja es triangular y sencilla, perfecta para talar "
"�rboles o cortar le�a.\n");
AddId(({"hacha_le�ador", "herramienta"}));
    AddAdjective(({"de","le�ador","lenyador"}));

}