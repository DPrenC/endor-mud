/* cascfl.c
   Creacion : Nemesis@Simauria
   Descripcion : Otro premio para los que lleguen al final del laberinto debajo
                de las mazmorras de Nandor.
*/


inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_CASCO, 0, P_SIZE_GENERIC, M_CUERO);
  SetAds(({"un", "ligero"}));
  AddId(({"armadura","casco","enmohecido"}));
  SetShort("un casco enmohecido");
  SetLong(
"Es un ligero casco rematado con un pincho de metal y decorado con un penacho\n\
de pelos y cintas de cuero. La humedad ha enmohecido el cuero del que esta\n\
hecho.\n");
  SetResetQuality(75);
  }