/* fichero: mandoble.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
  ::create();
  SetStandard(WT_MANDOBLE, 12, P_SIZE_LARGE, M_HIERRO);
  SetShort("un mandoble");
  SetLong(
  "Es una gran espada a dos manos. La empuñadura tiene una poderosa guarda de hierro con "
  "largos gabilanes terminados en puntas esféricas y pomo así mismo esférico.\n"
  "La pesada hoja de un metro veinte de longitud tiene  filos rectos y termina en una rotunda punta triangular.\n"
  "Las espadas a dos manos son armas de gran poderío y alcance, aunque es necesario una "
  "gran fuerza, constitución rotunda y gran dominio de los movimientos para sacarle todo "
  "su partido. Suele ser usada por las razas más corpulentas y de mayor altura y sus "
  "impactos resultan impresionantes.\n");
}