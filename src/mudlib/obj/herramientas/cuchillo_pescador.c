/*  fichero: cuchillo_pescador.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: 
CUCHILLO PARA limpiar los peces reci�n pescados eliminando espinas y v�sceras y dejarlos listos para cocinar....
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
 "Es un cuchillo peque�o, de mango revestido de metal, hoja corta, curva, estrecha y muy "
 "afilada. Sirve para abrir y limpiar los peces reci�n pescados.\n");
}