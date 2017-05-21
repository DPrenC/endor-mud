
/*
DESCRIPCION  : Serrucho para el quest del amuleto perdido
FICHERO      : /d/akallab/comun/quest/amuleto/serrucho.c
MODIFICACION : 26-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>


create() {
  ::create();
  SetStandard(WT_HACHA,1,P_SIZE_GENERIC,M_ACERO);
  SetAds(({"un","viejo","oxidado"}));
  SetIds(({"serrucho","sierra","amu_quest_01"}));
  SetShort("un viejo serrucho");
  SetLong("Es un viejo y oxidado serrucho de carpintero.\n");
  SetWeight(2000);
  SetValue(10);
  Set(P_GENDER, GENDER_MALE);
  SetResetQuality(60);
  SetNumberHands(1);
  //Set(P_NOSELL,1);
}
