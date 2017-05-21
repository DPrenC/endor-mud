/*
DESCRIPCION  : Vara de madera peque�a
FICHERO      : vara_p.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/


inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_VARA, 6, P_SIZE_SMALL, M_MADERA);
  SetAds(({"una","larga","peque�o"}));
  SetIds(({"arma","vara"}));
  SetShort("una vara peque�a");
  SetLong("Una larga vara de roble usada para golpear.\n");
  SetResetQuality(90);
  SetValue(QueryValue()*4);
  SetWeight(QueryWeight()*2);
}
