/*
DESCRIPCION    : arma base
FICHERO        : DIRECCION/FICHERO
CREACION       : 12-1-98 [koel].
U.MODIFICACION :
*/

inherit WEAPON;

#include "path.h"
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetAds(({"ancho","de acero"}));	
  SetIds(({"espada","sable"}));
  SetShort("Un sable");		
  SetLong(
"Es una espada con mango grande y la hoja curva. El filo esta un poco oxidado.\n"	
  );
  SetWC(8);		//danyo
  SetMaterial(M_ACERO);
  SetWeight(450*8);		//peso en gramos	
  SetValue(500*450*8/1000);		
  SetDamType(DT_SLASH);		//tipo de danyo
  SetWeaponType(WT_ALABARDA);	
  SetSize(P_SIZE_MEDIUM);
  SetResetQuality(80);	
  SetNumberHands(1);	
}
