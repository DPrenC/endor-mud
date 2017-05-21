/*=============================================================*
 |            << GREMIO: [m] Maler >>                          |
 *=============================================================*
 |               Creacion............. 31-10-00                |
 |               Ultima Modificacion.. 31-10-00                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include "path.h"
#include <properties.h>
#include <materials.h>
#include <guild.h>
inherit WEAPON;

create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_VARA,10,P_SIZE_GENERIC,M_ADAMANTIO);
 SetWeight(1100);
 SetValue(1000000);
 SetShort("una vara afilada");
 SetIds(({"vara"}));
 AddAdjective("afilada");
  Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong(W("Es una larga vara de una aleación especial, muy rara e infrecuente. Sus extremos están "
"afilados para conseguir mayor daño en combate, de cualquier forma, su uso es bastante complicado, por "
"lo que están protegidas para que no las usen los menos dotados.\n"));
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
	if (weapon!=TO) return EQ_OK;
  if (!wielder->QueryIsPlayer()) return EQ_OK;
  if (wielder->QueryGuild()!=GC_CONJURADORES)
    return "Una fuerza mística te impide empuñar la vara.\n";
  if (wielder->QueryGuildLevel()<30)
    return "Todavía no puedes usar la vara.\n";
  return ::ChkEquip(wielder, weapon, flags);
}
