/*  fichero: cuchillo_pescador.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: 
CUCHILLO PARA limpiar los peces recién pescados eliminando espinas y vísceras y dejarlos listos para cocinar....
*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO, 2,P_SIZE_GENERIC,M_HIERRO);
  AddId(({"cuchillo", "navaja", "cuchillo_pescador", "herramienta"}));
  AddAdjective(({"de", "pescador"}));
  SetShort("un cuchillo de pescador");
 SetLong(
 "Es un cuchillo pequeño, de mango revestido de metal, hoja corta, curva, estrecha y muy "
 "afilada. Sirve para abrir y limpiar los peces recién pescados.\n");
}