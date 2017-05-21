/*
DESCRIPCION    : baston pequeño. Es la  version pequeña del baston de lad-laurelin
FICHERO        : baculo_p.c
CREACION       : 10-11-01 [Bomber]
*/

inherit WEAPON;

#include "path.h"
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetAds(({"bello","un","el"}));
  SetIds(({"baculo","vara"}));
  SetShort("un baculo");	
  SetLong(
  "Es un fino baculo ornamentado en cuya base hay sujeta una bola.\n"			
  );

  SetMaterial(M_ORO);
  SetWC(4);		
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
  SetDamType(DT_BLUDGEON);	
  SetWeaponType(WT_MAZA);	
  SetSize(P_SIZE_SMALL);
  SetDamType(DT_BLUDGEON);		
  SetResetQuality(100);	
  SetNumberHands(2);	
}
