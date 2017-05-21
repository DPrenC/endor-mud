/* Fichero: lanza.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_LANZA, 8, P_SIZE_GENERIC, M_HIERRO);
   SetShort("una lanza");
   SetLong(
   "La lanza es un arma muy sencilla formada por un mango de unos dos metros de largo y "
   "una punta o moharra de hierro de forma cónica u ovalada. Suele ser producida en "
   "grandes cantidades y utilizada por infantería y caballería indistintamente.\n"
   "Habitualmente resulta muy útil en formaciones cerradas aunque algunas versiones más "
   "cortas son utilizadas por exploradores y batidores. Su simplicidad las hace ser el "
   "arma preferida de los aventureros de las razas menos avanzadas.\n");
}