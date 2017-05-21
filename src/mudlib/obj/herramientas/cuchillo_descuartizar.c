/*  fichero: cuchillo_descuartizar.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: 
CUCHILLO PARA descuartizar  CUERPOS sacando partes aprovechables.
*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO, 3,P_SIZE_GENERIC,M_ACERO);
  AddId(({"cuchillo", "herramienta", "cuchillo_descuartizar", "cuchillo_descuartizar"}));
  SetAds(({"descuartizador", "de", "caza", "cazador", "descuartizar"}));
  SetShort("un cuchillo de caza");
  SetLong(
  "Es un gran cuchillo de monte, de hoja algo pesada, afilada y curva. Solo dispone de un "
  "filo pero en el reverso de la hoja, desde el punto que comienza a curvarse hacia "
  "arriba, dispone de una sección cortante, lo que lo hace ideal para rematar a las "
  "presas cazadas o incrustar la punta en los intersticios de articulaciones para "
  "separar las distintas piezas del cuerpo de un animal. El mango es de recia madera, "
  "ligeramente curvado hacia abajo. En la primera porción del filo inferior partiendo de "
  "la empuñadura, dispone de unos cuantos dientes de sierra ideales para raspar o cortar "
  "huesos y tendones. Sin duda una herramienta muy útil para un cazador en busca de carne.\n");
}