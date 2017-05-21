/* [Cs] Chaos
	04-10-99 [Cs] Modificacion
	25-10-99 [Woo] Modificada porque hacha es masculino
*/	
#include <combat.h>
#include <properties.h>
#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_HACHA,8,P_SIZE_MEDIUM,M_HIERRO);
 SetWeight(5000); // Aumentado el peso
 SetShort("un hacha de combate");
 SetIds(({"hacha","hacha de combate"}));
 SetValue(3000);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es un hacha de combate forjada por los mejores herreros orcos. Sus aspecto\n\
es un poco tosco pero es muy útil. Es de doble hoja metalica y bien afilada.\n");
}


