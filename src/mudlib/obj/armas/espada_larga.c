/* fichero: espada_larga.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_HIERRO);
  SetShort("una espada larga");
  SetLong(
"Es una espada de doble filo, cuya  larga hoja de unos noventa centímetros de longitud "
"se va estrechando desde la empuñadura hasta formar la aguzada punta. La empuñadura "
  "envuelta en cuero y tejido de fina cuerda posee un pomo metálico con forma "
  "trapezoidal y una guarda formada por dos sencillos gabilanes de hierro rectos y con "
  "unos sencillos grabados geométricos.\n"
  "La espada es el arma preferida por la mayoría de los Pueblos Libres del noroeste de "
  "la Tierra Media y su versatilidad y fiabilidad la convierten en el arma más "
  "importante de la panoplia de infantes, jinetes, aventureros, exploradores y "
  "montaraces.\n");
}