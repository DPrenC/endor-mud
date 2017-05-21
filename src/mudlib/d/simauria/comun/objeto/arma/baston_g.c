/*
DESCRIPCION    : baston. Es la version grande del baston de lad-laurelin
FICHERO        : baston_g.c
CREACION       : 10-11-01 [Bomber]
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_VARA,3,P_SIZE_LARGE,M_MADERA);
  SetAds(({"de madera","un","el"}));
  SetIds(({"baston","palo","vara"}));
  SetShort("un baston de madera");	
  SetLong(
  "Es una bonita vara hecha en madera tallada.\n"			
  );
  /*3*/
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
  SetResetQuality(95);	
  SetNumberHands(2);	
}
