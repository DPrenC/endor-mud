// Arma de JAN est�ndar

inherit "std/weapon";
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_ACERO);
  SetAds(({"una","brillante","de acero"}));
  SetIds(({"arma"}));
  SetShort("un arma bastante buena");
  SetLong("Es una arma que el Gremio de Guerreros entrega s�lo a los mejores guerreros.\n");
  AddSubDetail(({"s�mbolo","simbolo","extra�o s�mbolo","extranyo s�mbolo",
                "extra�o simbolo","extranyo simbolo"}),
                "Parece el emblema del Gremio de Guerreros.\n");
  SetWeight(QueryWeight()-500);
  Set(P_NOSELL,1);
  SetResetQuality(100);
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  if (wielder->QueryGuild()=="guerrero" && wielder->QueryGuildLevel()>30)
    return ::ChkEquip(wielder, weapon, flags);
  else
    return "S�lo los mejores guerreros pueden empu�ar este arma.\n";
}
