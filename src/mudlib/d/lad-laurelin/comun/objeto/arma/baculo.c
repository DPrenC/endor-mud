/*
DESCRIPCION    : baston
FICHERO        : /d/lad-laurelin/comun/objeto/arma/baculo.c
CREACION       : 17-2-99
U.MODIFICACION :
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
  SetWeight(300*4);	
  SetValue(600*4*200/1000);		
  SetDamType(DT_BLUDGEON);	
  SetWeaponType(WT_MAZA);	
  SetSize(P_SIZE_MEDIUM);
  SetDamType(DT_BLUDGEON);		
  SetResetQuality(100);	
  SetNumberHands(2);	
}
