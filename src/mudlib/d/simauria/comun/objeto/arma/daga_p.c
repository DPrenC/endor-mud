/*
DESCRIPCION  : Daga pequeña
FICHERO      : daga_p.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/


inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_CUCHILLO, 2, P_SIZE_SMALL, M_ACERO);
  SetAds(({"una","pequeña"}));
  SetIds(({"daga","arma"}));
  SetShort("una daga pequeña");
  SetLong(
"Es una daga de hoja corta y afilada.\n");
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
SetDamType(DT_PIERCE);
Set(P_GENDER,GENDER_FEMALE);
}
