/*
DESCRIPCION    : baston
FICHERO        : /d/lad-laurelin/comun/objeto/arma/baston.c
CREACION       : 17-2-99
U.MODIFICACION :
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_VARA,3,P_SIZE_MEDIUM,M_MADERA);
  SetAds(({"de madera","un","el"}));
  SetIds(({"baston","palo","vara"}));
  SetShort("un baston de madera");	
  SetLong(
  "Es una bonita vara hecha en madera tallada.\n"			
  );
  /*3*/
  SetWeight(300*3);	
  SetValue(300*3*200/1000);		  		
  SetResetQuality(95);	
  SetNumberHands(1);	
}
