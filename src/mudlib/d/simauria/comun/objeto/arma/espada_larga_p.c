/*
DESCRIPCION  : Espada larga grande
FICHERO      : espada_larga_p.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/


inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "./path.h"
create() {
  ::create();
  SetStandard(WT_ESPADA, 7, P_SIZE_SMALL, M_ACERO);
  SetAds(({"una","larga","pequeña"}));
  SetIds(({"espada","arma"}));
  SetShort("una espada larga pequeña");
  SetLong(W(
"Es una espada larga.\n"));
SetDamType(DT_SLASH);
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
Set(P_GENDER,GENDER_FEMALE);
}
