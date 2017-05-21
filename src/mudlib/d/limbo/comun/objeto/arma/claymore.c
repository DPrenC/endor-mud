/*
DESCRIPCION  : Seccion de armas de filo en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/armas1.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ESPADA,5,P_SIZE_GENERIC,M_ACERO);
  SetAds(({"una","tosca"}));
  SetIds(({"claymore","arma"}));
  SetShort("una pesada claymore");
  SetLong(
     "Es una pesada espada de hoja recta, de la que sobresalen dos largas hojas\n"
     "orientadas oblicuamente. En general parece algo tosca, pero es efectiva.\n");
  SetValue(15);
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(85);
  SetNumberHands(2);
  Set(P_NOSELL,1);
}
