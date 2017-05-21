/*
DESCRIPCION  : Vara de madera grande
FICHERO      : vara_g.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/


inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_VARA, 6, P_SIZE_LARGE, M_MADERA);
  SetAds(({"una","larga","gran","grande"}));
  SetIds(({"arma","vara"}));
  SetShort("una vara grande");
  SetLong("Una larga vara de roble usada para golpear.\n");
  SetResetQuality(90);
  SetValue(QueryValue()*4);
  SetWeight(QueryWeight()*2);
}
