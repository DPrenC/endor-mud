/*
DESCRIPCION  : Cuchillo grande basado en el de kenton
FICHERO      : cuchillo_g.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/
inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetAds(({"un","el"}));
  SetIds(({"cuchillo"}));
  SetShort("una daga");
  SetLong(
"Un pequenyo cuchillo. Parece de bastante calidad. Tiene una empunyadura "
"de madera.\n");
  SetWeaponType(WT_CUCHILLO);
  SetWC(2);
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
  SetDamType(DT_PIERCE);
  SetWeaponType(WT_CUCHILLO);
  SetSize(P_SIZE_LARGE);
  SetMaterial(M_ACERO);
  SetResetQuality(95);
  SetNumberHands(1);
}
