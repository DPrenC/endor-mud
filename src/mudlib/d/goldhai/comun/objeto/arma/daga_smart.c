/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 07-10-98                |
 |               Ultima Modificacion.. 07-10-98                |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_CUCHILLO,1,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(350);
 SetShort("una daga");
 SetIds(({"daga"}));
 SetValue(3500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Puedes ver una magnifica daga con la empuñadura de marfil y con piedras\n\
preciosas incrustadas. La hoja brilla y refleja tu rostro en ella.\n");
}
