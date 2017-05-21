// Arma de JAN para la sede de Nandor
// [n] nemesis@simauria
// Modificado: 27-02-2003 [n] Cambiado para que herede un arma estándar.

inherit "/guilds/guerreros/jan_obj/jan_arma";

#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_MITHRIL);
  SetAds(({"una","brillante","de acero"}));
  SetIds(({"katana","arma","espada"}));
  SetShort("una brillante katana");
  SetLong("Es una espada de hoja brillante y muy afilada. Parece bastante ligera\n");
  AddSubDetail(({"símbolo","simbolo","extraño símbolo","extranyo símbolo",
                "extraño simbolo","extranyo simbolo"}),
                "Parece el emblema del gremio del Gremio de Guerreros.\n");
  SetWeight(QueryWeight()-500);
}
