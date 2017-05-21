
/*
DESCRIPCION  : tablon de madera para el quest del amuleto perdido
FICHERO      : /d/akallab/comun/quest/amuleto/tablon.c
MODIFICACION : 26-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>


create() {
  ::create();
  SetStandard(WT_MAZA,1,P_SIZE_GENERIC,M_MADERA);
  SetAds(({"un","largo","de madera"}));
  SetIds(({"tablon","amu_quest_02"}));
  SetShort("un tablon de madera");
  SetLong("Es un largo tablon de madera de roble.\n");
  SetWeight(3000);
  SetValue(100);
  Set(P_GENDER, GENDER_MALE);
  SetResetQuality(100);
  SetNumberHands(2);
  //Set(P_NOSELL,1);
}
