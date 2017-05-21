/*  fichero: cuchillo_tallar.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: 
CUCHILLO PARA tallar la madera, hacer flechas, grabar o adornar....
*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO, 2,P_SIZE_GENERIC,M_HIERRO);
  AddId(({"cuchillo", "navaja", "cuchillo_artesano", "cuchillo_carpintero", "herramienta"}));
  AddAdjective(({"de", "tallar"}));
  SetShort("un cuchillo de tallar");
  SetLong(
  "Es un cuchillo pequeño de mango torneado que facilita el agarre y un manejo preciso.\n"
  "La hoja, corta y ancha está terminada en una aguzada punta.  Unas pequeñas estrías "
  "afiladas colocadas en el reverso son utilizadas para realizar pequeñas tallas y "
  "marcas precisas en la madera. Una herramienta ligera y útil para todos los amantes "
  "de la talla.\n");
}