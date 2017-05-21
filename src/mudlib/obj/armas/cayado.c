/* fichero: cayado.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_CAYADO, 6, P_SIZE_GENERIC, M_MADERA);
   SetIds(({"cayado","baston","bastón", "arma"}));
   SetAds(({"de", "madera"}));
  SetShort("un cayado");
  SetLong(
  "Es un cayado para caminar, fuerte, nudoso y tallado con algunos motivos sencillos.\n"
  "Mide aproximadamente un metro y medio y parece una robusta herramienta para "
  "auxiliar a los abezados viajeros en su vagabundear, así como propinar contundentes "
  "golpazos de ser necesario. Sin duda podría convertirse en manos expertas en un arma "
  "digna de tener en cuenta.\n");
}