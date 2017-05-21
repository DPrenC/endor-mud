/*
DESCRIPCION  : Claymore Grande como el del limbo
FICHERO      : claymore_g.c.c
CREACION     : 10-11-01 [Bomber]
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ESPADA,5,P_SIZE_LARGE,M_ACERO);
  SetAds(({"una","tosca"}));
  SetIds(({"claymore","arma"}));
  SetShort("pesada claymore");
  SetLong(
     "Es una pesada espada de hoja recta, de la que sobresalen dos largas hojas "
     "orientadas oblicuamente. En general parece algo tosca, pero es efectiva.\n");
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(85);
  SetNumberHands(2);
}
