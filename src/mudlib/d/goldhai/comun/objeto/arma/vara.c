/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-12-99                |
 |               Ultima Modificacion.. 02-12-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <materials.h>
#include <properties.h>
#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_VARA,4,P_SIZE_GENERIC,M_MADERA);
 SetWeight(1100);
 SetShort("una vara de madera");
 SetIds(({"vara"}));
 AddAdjective("madera");
 AddAdjective("de madera");
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("Ves una larga vara de madera.\n");
}
