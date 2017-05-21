/*
DESCRIPCION  : Espada
FICHERO      : /d/limbo/comun/objeto/arma/espada.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
               30-07-07 [Angor@Simauria] Nuevos niveles de armas
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ESPADA,4,P_SIZE_GENERIC,M_HIERRO);
  SetAds(({"una","tosca"}));
  SetIds(({"espada","arma"}));
  SetShort("una espada");
  SetLong("Es una espada de hoja recta del tipo mas comun.\n");
  SetValue(25);
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(100);
  SetNumberHands(1);
  Set(P_NOSELL,1);
}
