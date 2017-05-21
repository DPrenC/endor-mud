/* fichero: espada_larga.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_HIERRO);
  SetShort("una espada larga");
  SetLong(
"Es una espada de doble filo, cuya  larga hoja de unos noventa cent�metros de longitud "
"se va estrechando desde la empu�adura hasta formar la aguzada punta. La empu�adura "
  "envuelta en cuero y tejido de fina cuerda posee un pomo met�lico con forma "
  "trapezoidal y una guarda formada por dos sencillos gabilanes de hierro rectos y con "
  "unos sencillos grabados geom�tricos.\n"
  "La espada es el arma preferida por la mayor�a de los Pueblos Libres del noroeste de "
  "la Tierra Media y su versatilidad y fiabilidad la convierten en el arma m�s "
  "importante de la panoplia de infantes, jinetes, aventureros, exploradores y "
  "montaraces.\n");
}