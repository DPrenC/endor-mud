/* fichero: espada_ancha.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_ESPADA, 6, P_SIZE_GENERIC, M_HIERRO);
  SetAds(({"una","ancha"}));
  SetIds(({"espada","arma","espada ancha"}));
  SetShort("una espada ancha");
  SetLong(
"La espada ancha se diferencia de la larga en que su hoja tiene mayor anchura y grosor, "
"con lo cual se consigue un arma de filo mas resistente y hoja más pesada, manejada "
  "para propinar tajos a corta distancia. La empuñadura es muy sencilla, de pomo apenas "
  "mas grueso que la espiga. Los gabilanes, que se engrosan de la cruz hacia los "
  "extremos, son rectos y de forma cuadrangular.\n");
 SetWeight(2650);
}