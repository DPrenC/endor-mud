/*  fichero: cuchillo_tallar.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: 
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
  "Es un cuchillo peque�o de mango torneado que facilita el agarre y un manejo preciso.\n"
  "La hoja, corta y ancha est� terminada en una aguzada punta.  Unas peque�as estr�as "
  "afiladas colocadas en el reverso son utilizadas para realizar peque�as tallas y "
  "marcas precisas en la madera. Una herramienta ligera y �til para todos los amantes "
  "de la talla.\n");
}