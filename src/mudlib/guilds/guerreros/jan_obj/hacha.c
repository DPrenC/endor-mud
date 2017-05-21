// Hacha para la sede de Kha-Annu

inherit "/guilds/guerreros/jan_obj/jan_arma";
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_HACHA, 9, P_SIZE_GENERIC, M_HIERRO);
  SetAds(({"una","brillante","de hierro"}));
  SetIds(({"hacha","enana"}));
  SetShort("una brillante hacha enana");
  SetLong("Es un hacha de hoja brillante y muy afilada, de perfecta manufactura enana.\n"
  "Tiene un símbolo a cada lado de la hoja y parece bastante ligera.\n");
  AddSubDetail(({"símbolo","simbolo","extraño símbolo","extranyo símbolo",
                "extraño simbolo","extranyo simbolo"}),
                "Parece el emblema del Gremio de Guerreros.\n");
  SetWeight(QueryWeight());
  Set(P_NOSELL,1);
  SetResetQuality(100);
}
